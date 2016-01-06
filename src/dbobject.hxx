#ifndef DBOBJECT_HXX
#define DBOBJECT_HXX

#include <string>

#include "idbobject.hxx"

class DBObject : public IDBObject
{
    public:
        //! Constructor.
        /*!
         * \param name The object name
         */
        DBObject(std::string name);

        const std::string& name() const;
    private:
        std::string m_name;
};

#endif // DBOBJECT_HXX
