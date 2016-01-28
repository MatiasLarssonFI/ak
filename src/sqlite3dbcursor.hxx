#ifndef DBCURSOR_HXX
#define DBCURSOR_HXX

#include <functional>
#include <vector>
#include <stdexcept>

#include <SQLiteCpp/SQLiteCpp.h>

#include "idbcursor.hxx"
#include "alias.hxx"

//! SQLite3 database cursor.
/*!
 * The DBCursor object is not MoveCostructible nor MoveAssignable.
 *
 * \tparam T Must be MoveConstructible
 */
template <class T>
class SQLite3DBCursor : public IDBCursor<T>
{
    public:
        //! A Callable that takes a vector of columns and returns a new instance based on that.
        using FConstr = std::function<T(std::vector<SQLite::Column>)>;

        //! Constructor.
        /*!
         * \param stm The statement object
         * \param callback Callable used to construct a T object for each row
         */
        SQLite3DBCursor(SQLite::Statement& stm, FConstr callback)
            : m_stm(stm)
            , m_cb(std::move(callback))
            , m_p_current(nullptr)
        {
            this->_loadNext();
        }


        T next() {
            if (this->hasNext()) {
                T ret = std::move(*m_p_current);
                this->_loadNext();
                return ret;
            }

            throw std::runtime_error("No more rows in sequence");
        }

        bool hasNext() const {
            return (bool)m_p_current;
        }

        SQLite3DBCursor(SQLite3DBCursor const &) = delete;
        SQLite3DBCursor& operator=(SQLite3DBCursor const &) = delete;
    private:
        void _loadNext() {
            m_p_current.reset(nullptr);
            if (m_stm.executeStep()) {
                std::vector<SQLite::Column> cols;

                for(unsigned i = 0; i < m_stm.getColumnCount(); ++i) {
                    cols.push_back(m_stm.getColumn(i));
                }

                m_p_current.reset(new T(m_cb(std::move(cols))));
            }
        }

        SQLite::Statement& m_stm;
        FConstr m_cb;
        uptr<T> m_p_current;
};

#endif // DBCURSOR_HXX
