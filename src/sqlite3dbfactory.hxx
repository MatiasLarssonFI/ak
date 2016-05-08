#ifndef SQLITEDBFACTORY_HXX
#define SQLITEDBFACTORY_HXX

#include <string>

#include "alias.hxx"
#include "idbfactory.hxx"
#include "idbobject.hxx"


class SQLite3DBFactory : public IDBFactory {
    uptr<IDBObject> getDBObject(std::string name);
};

#endif // SQLITEDBFACTORY_HXX
