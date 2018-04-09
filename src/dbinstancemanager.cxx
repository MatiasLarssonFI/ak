#include "dbinstancemanager.hxx"
#include "dbconfig.hxx"
#include "sqlite3dbfactory.hxx"

#include <stdexcept>

#include <SQLiteCpp/SQLiteCpp.h>
#include <sqlite3.h>

DBInstanceManager::DBInstanceManager()
    : m_db(DBConfig::getInstance().filename(), SQLITE_OPEN_READWRITE)
    , m_db_f(new SQLite3DBFactory(m_db))
{
    if (DBConfig::getInstance().filename().empty()) {
        throw std::invalid_argument("DB filename must not be empty");
    }
}


DBInstanceManager::t_db& DBInstanceManager::getDB() {
    return m_db;
}


DBInstanceManager::t_db_f const & DBInstanceManager::getDBFactory() const {
    return m_db_f;
}
