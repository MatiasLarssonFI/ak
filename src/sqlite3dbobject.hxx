#ifndef SQLITE3DBOBJECT_HXX
#define SQLITE3DBOBJECT_HXX

#include <string>
#include <SQLiteCpp/SQLiteCpp.h>

#include "idbobject.hxx"
#include "alias.hxx"


//! DBObject implemented for an SQLite3 DB.
class SQLite3DBObject : public IDBObject
{
    public:
        using t_db = SQLite::Database;
        using t_statement = SQLite::Statement;

        SQLite3DBObject(std::string name, t_db& db);

        const std::string& name() const;
        unsigned id() const;
        bool exists() const;

        void create();
        void addComponent(std::string component_name) const;
        void addGeneralization(std::string gen_name) const;

        uptr<IDBObject::DBCursor> componentCursor() const;
        uptr<IDBObject::DBCursor> generalizationCursor() const;

    private:
        //! Returns an SQLite3DBObject DBcursor
        /*!
         * \param pStm The query result may contain only one column; the name
         */
        uptr<IDBObject::DBCursor> _cursor(uptr<t_statement> p_stm) const;

        std::string m_name;
        t_db& m_db;
        unsigned m_id;
};

#endif // SQLITE3DBOBJECT_HXX
