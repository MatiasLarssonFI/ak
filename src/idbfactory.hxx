#ifndef IDBFACTORY_HXX
#define IDBFACTORY_HXX

#include "alias.hxx"
#include "idbobject.hxx"

class IDBFactory
{
    public:
        virtual uptr<IDBObject> getDBObject(std::string name) = 0;
};

#endif // IDBFACTORY_HXX
