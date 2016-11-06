#include <string>

#include "sqlite3dbfactory.hxx"
#include "idbobject.hxx"
#include "sqlite3dbobject.hxx"
#include "alias.hxx"


SQLite3DBFactory::SQLite3DBFactory(SQLite::Database& db)
    : m_db(db)
{}

uptr<IDBObject> SQLite3DBFactory::getDBObject(std::string name) const {
    return uptr<IDBObject>(new SQLite3DBObject(std::move(name), m_db));
}
