#ifndef DBINSTANCEMANAGER_HXX
#define DBINSTANCEMANAGER_HXX

#include "alias.hxx"
#include "idbfactory.hxx"

#include <SQLiteCpp/SQLiteCpp.h>


class DBInstanceManager
{
    public:
        using t_db = SQLite::Database;
        using t_db_f = uptr<IDBFactory>;

        DBInstanceManager();
        DBInstanceManager(DBInstanceManager const &) = delete;
        DBInstanceManager& operator=(DBInstanceManager const &) = delete;

        t_db& getDB();
        t_db_f const & getDBFactory() const;
    private:
        t_db m_db;
        const t_db_f m_db_f;
};

#endif // DBINSTANCEMANAGER_HXX
