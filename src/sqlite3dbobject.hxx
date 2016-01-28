#ifndef SQLITE3DBOBJECT_HXX
#define SQLITE3DBOBJECT_HXX

#include <string>
#include <SQLiteCpp/SQLiteCpp.h>

#include "idbobject.hxx"
#include "idbcursor.hxx"
#include "alias.hxx"


//! DBObject implemented for an SQLite3 DB.
class SQLite3DBObject : public IDBObject
{
    public:
        SQLite3DBObject(std::string name);

        const std::string& name() const;

        void addProperty(std::string property_name) const;
        void addGeneralization(std::string gen_name) const;

        uptr<IDBObject::DBCursor> propertyCursor() const;
        uptr<IDBObject::DBCursor> generalizationCursor() const;
    private:
        uptr<IDBObject::DBCursor> cursor(SQLite::Statement& stm) const;

        std::string m_name;
};

#endif // SQLITE3DBOBJECT_HXX
