#include "dbfactoryutil.hxx"
#include "idbfactory.hxx"
#include "sqlite3dbfactory.hxx"
#include "alias.hxx"

sptr<IDBFactory> ak_util::getDBFactory() {
    static sptr<IDBFactory> inst(new SQLite3DBFactory());
    return inst;
}
