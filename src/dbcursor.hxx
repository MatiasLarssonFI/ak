#ifndef DBCURSOR_HXX
#define DBCURSOR_HXX

#include <functional>
#include <unordered_map>

#include <SQLiteCpp/SQLiteCpp.h>
#include "idbcursor.hxx"

//! Database cursor.
template <class T>
class DBCursor : public IDBCursor
{
    public:
        // RowFieldSet's keys are column names
        using RowFieldSet = std::unordered_map<std::string, SQLite::Column>;

        //! Constructor.
        /*!
         * \param db The database handle
         * \param sql The SQL query
         * \param constr_callback A Callable that takes a RowFieldSet and returns a new instance based on that.
         */
        DBCursor(SQLite::Database& db,
                    std::string sql,
                    std::function<T(RowFieldSet const & fields)> constr_callback);

        T next();
        bool hasNext() const;
    private:
        SQLite::Database& m_db;
};

#endif // DBCURSOR_HXX
