#ifndef IDBOBJECT_HXX
#define IDBOBJECT_HXX

#include <string>

#include "idbcursor.hxx"
#include "alias.hxx"


//! An object that can be stored in the database.
class IDBObject
{
    public:
        using DBCursor = IDBCursor<IDBObject>;

        //! Returns the object's name
        virtual const std::string& name() const = 0;


        //! Adds a property relation.
        /*!
         * If no object exists with property_name,
         * one is created. The object named property_name
         * is associated with this object as a property.
         */
        virtual void addProperty(std::string property_name) const = 0;


        //! Adds a generalization relation.
        /*!
         * If no object exists with gen_name,
         * one is created. The object named gen_name
         * is associated with this object as a generalization.
         */
        virtual void addGeneralization(std::string gen_name) const = 0;


        //! Returns a cursor to the properties.
        virtual uptr<DBCursor> propertyCursor() const = 0;


        //! Returns a cursor to the generalizations.
        virtual uptr<DBCursor> generalizationCursor() const = 0;
};

#endif // IDBOBJECT_HXX
