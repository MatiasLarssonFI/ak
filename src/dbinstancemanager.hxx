#ifndef DBINSTANCEMANAGER_HXX
#define DBINSTANCEMANAGER_HXX

#include "alias.hxx"
#include "idbfactory.hxx"

#include <SQLiteCpp/SQLiteCpp.h>


//! Manages database object instances.
class DBInstanceManager
{
    public:
        using t_db = SQLite::Database;
        using t_db_f = uptr<IDBFactory>;

        DBInstanceManager();
        DBInstanceManager(DBInstanceManager const &) = delete;
        DBInstanceManager& operator=(DBInstanceManager const &) = delete;

        //! Returns the SQLite database object.
        t_db& getDB();

        //! Returns the IDBFactory object
        t_db_f const & getDBFactory() const;
    private:
        t_db m_db;
        const t_db_f m_db_f;
};

#endif // DBINSTANCEMANAGER_HXX
