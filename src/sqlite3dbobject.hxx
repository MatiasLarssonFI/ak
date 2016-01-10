#ifndef SQLITE3DBOBJECT_HXX
#define SQLITE3DBOBJECT_HXX

#include <string>

#include "idbobject.hxx"
#include "idbcursor.hxx"


//! DBObject implemented for an SQLite3 DB.
class SQLite3DBObject : public IDBObject
{
    public:
        SQLite3DBObject(std::string name);

        const std::string& name() const;
    private:
        std::string m_name;
};

#endif // SQLITE3DBOBJECT_HXX
