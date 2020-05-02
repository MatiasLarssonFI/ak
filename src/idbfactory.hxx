#ifndef IDBFACTORY_HXX
#define IDBFACTORY_HXX

#include "alias.hxx"
#include "idbobject.hxx"
#include "objectexpression.hxx"

class IDBFactory
{
    public:
        IDBFactory() = default;

        virtual uptr<IDBObject> getDBObject(std::string name) const = 0;
        virtual uptr<IDBObject> getDBObject(ObjectExpression const & expr) const = 0;
        virtual ~IDBFactory() = default;
        // rule of zero. These must be defaulted since the destructor is user-defined.
        IDBFactory(IDBFactory const &) = default;
        IDBFactory(IDBFactory &&) = default;
        IDBFactory& operator=(IDBFactory const &) = default;
        IDBFactory& operator=(IDBFactory &&) = default;
};

#endif // IDBFACTORY_HXX
