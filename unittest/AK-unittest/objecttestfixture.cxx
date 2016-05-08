#include <SQLiteCpp/SQLiteCpp.h>
#include <iostream>

#include "objecttestfixture.hxx"
#include "dbfactoryutil.hxx"
#include "dbconfig.hxx"


ObjectTestFixture::ObjectTestFixture()
    : m_db_factory(ak_util::getDBFactory())
{

}

ObjectTestFixture::~ObjectTestFixture()
{
    SQLite::Database db(DBConfig::getInstance().filename(), SQLITE_OPEN_READWRITE);
    db.exec("delete from object;");
}
