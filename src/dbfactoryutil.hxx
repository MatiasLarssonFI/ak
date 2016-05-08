#ifndef DBFACTORYUTIL
#define DBFACTORYUTIL

#include "idbfactory.hxx"
#include "alias.hxx"

namespace ak_util {
    sptr<IDBFactory> getDBFactory();
}

#endif // DBFACTORYUTIL
