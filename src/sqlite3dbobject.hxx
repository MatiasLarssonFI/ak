#ifndef SQLITE3DBOBJECT_HXX
#define SQLITE3DBOBJECT_HXX

#include <string>
#include <SQLiteCpp/SQLiteCpp.h>

#include "sqlite3dbcursor.hxx"
#include "idbobject.hxx"
#include "idbcursor.hxx"
#include "alias.hxx"


//! DBObject implemented for an SQLite3 DB.
class SQLite3DBObject : public IDBObject
{
    public:
        using t_db = SQLite::Database;
        using t_statement = SQLite::Statement;

        SQLite3DBObject(std::string name);

        const std::string& name() const;
        bool exists() const;

        void create();
        void addComponent(std::string component_name) const;
        void addGeneralization(std::string gen_name) const;

        uptr<IDBObject::DBCursor> componentCursor() const;
        uptr<IDBObject::DBCursor> generalizationCursor() const;

    protected:
        //! Factory method to get the SQLite::Database instance.
        t_db& _getDBInstance() const;

    private:
        //! Returns an SQLite3DBObject DBcursor
        /*!
         * \param stm The query result may contain only one column; the name
         */
        uptr<IDBObject::DBCursor> _cursor(t_statement& stm) const;

        std::string m_name;
        SQLite::Database& m_db;
        unsigned m_id;
};

#endif // SQLITE3DBOBJECT_HXX
