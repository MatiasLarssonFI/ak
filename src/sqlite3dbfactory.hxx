#ifndef SQLITEDBFACTORY_HXX
#define SQLITEDBFACTORY_HXX

#include <string>

#include "alias.hxx"
#include "idbfactory.hxx"
#include "idbobject.hxx"

#include <SQLiteCpp/SQLiteCpp.h>


class SQLite3DBFactory : public IDBFactory {
    public:
        SQLite3DBFactory(SQLite::Database& db);
        uptr<IDBObject> getDBObject(std::string name) const;

    private:
        SQLite::Database& m_db;
};

#endif // SQLITEDBFACTORY_HXX
