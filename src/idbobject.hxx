#ifndef IDBOBJECT_HXX
#define IDBOBJECT_HXX

#include <string>


//! An object that can be stored in the database.
/*!
 * Generalizations and properties are evaluated at
 * save().
 */
class IDBObject
{
    public:
        //! Returns the object's name
        virtual const std::string& name() const = 0;

        //! Saves the object relations
        /*!
         * \throw std::runtime_exception On failure
         */
        virtual void save() = 0;

        //! Adds a property relation.
        /*!
         * If no object exists with property_name,
         * one is created. The object named property_name
         * is associated with this object as a property.
         */
        virtual void addProperty(std::string property_name);


        //! Adds a generalization relation.
        /*!
         * If no object exists with gen_name,
         * one is created. The object named gen_name
         * is associated with this object as a generalization.
         */
        virtual void addGeneralization(std::string gen_name);
};

#endif // IDBOBJECT_HXX
