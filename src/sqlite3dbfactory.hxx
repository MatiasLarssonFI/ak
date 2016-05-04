#ifndef SQLITEDBFACTORY_HXX
#define SQLITEDBFACTORY_HXX

#include "alias.hxx"
#include "idbfactory.hxx"
#include "sqlite3dbobject.hxx"


class SQLite3DBFactory : public IDBFactory {
    uptr<IDBObject> getDBObject(std::string name);
};

#endif // SQLITEDBFACTORY_HXX
