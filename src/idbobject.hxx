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


        //! Returns the object's ID.
        /*!
         * This method is rarely necessary as name() is
         * always unique. This method is intended to be
         * used only in database management.
         */
        virtual unsigned id() const = 0;


        //! Returns true if the object exists in the DB.
        virtual bool exists() const = 0;


        //! Adds the object to the DB.
        /*!
         * Inserts the object to the database. Will fail
         * and throw if the object already exists.
         *
         * After this method returns, id() will return the
         * DB ID.
         *
         * \throw std::logic_error If the object already exists
         */
        virtual void create() = 0;


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


        virtual ~IDBObject() = default;
        // rule of zero. These must be defaulted since the destructor is user-defined.
        IDBObject(IDBObject const &) = default;
        IDBObject(IDBObject &&) = default;
        IDBObject& operator=(IDBObject const &) = default;
        IDBObject& operator=(IDBObject &&) = default;
};

#endif // IDBOBJECT_HXX
