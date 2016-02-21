#ifndef IDBOBJECT_HXX
#define IDBOBJECT_HXX

#include <string>

#include "idbcursor.hxx"
#include "alias.hxx"


//! An object that can be stored in the database.
class IDBObject
{
    public:
        using DBCursor = IDBCursor<uptr<IDBObject>>;

        //! Returns the object's name
        virtual const std::string& name() const = 0;


        //! Adds a composition relation.
        /*!
         * If no object exists with component_name,
         * one is created. The object named component_name
         * is associated with this object as a component.
         */
        virtual void addComponent(std::string component_name) const = 0;


        //! Adds a generalization relation.
        /*!
         * If no object exists with gen_name,
         * one is created. The object named gen_name
         * is associated with this object as a generalization.
         */
        virtual void addGeneralization(std::string gen_name) const = 0;


        //! Returns a cursor to the components.
        virtual uptr<DBCursor> componentCursor() const = 0;


        //! Returns a cursor to the generalizations.
        virtual uptr<DBCursor> generalizationCursor() const = 0;
};

#endif // IDBOBJECT_HXX
