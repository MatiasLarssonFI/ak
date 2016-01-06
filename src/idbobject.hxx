#ifndef IDBOBJECT_HXX
#define IDBOBJECT_HXX

#include <string>

class IDBObject
{
    public:
        //! Returns the object's name
        virtual const std::string& name() const = 0;
};

#endif // IDBOBJECT_HXX
