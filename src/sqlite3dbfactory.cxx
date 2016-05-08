#include <string>

#include "sqlite3dbfactory.hxx"
#include "idbobject.hxx"
#include "sqlite3dbobject.hxx"
#include "alias.hxx"


uptr<IDBObject> SQLite3DBFactory::getDBObject(std::string name) {
    return uptr<IDBObject>(new SQLite3DBObject(std::move(name)));
}
