#ifndef IDBFACTORY_HXX
#define IDBFACTORY_HXX

#include "alias.hxx"
#include "idbobject.hxx"

class IDBFactory
{
    public:
        virtual uptr<IDBObject> getDBObject(std::string name) const = 0;
        virtual ~IDBFactory() {}
};

#endif // IDBFACTORY_HXX
