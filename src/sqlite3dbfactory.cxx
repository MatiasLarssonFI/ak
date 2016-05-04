#include "sqlite3dbfactory.hxx"
#include "alias.hxx"


uptr<IDBObject> SQLite3DBFactory::getDBObject(std::string name) {
    return uptr<IDBObject>(new SQLite3DBObject(std::move(name)));
}
