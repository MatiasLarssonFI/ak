#include <SQLiteCpp/SQLiteCpp.h>
#include <iostream>

#include "objecttestfixture.hxx"


ObjectTestFixture::ObjectTestFixture()
    : m_db_factory(m_db_inst_man.getDBFactory())
{

}

ObjectTestFixture::~ObjectTestFixture()
{

    DBInstanceManager::t_db& db = m_db_inst_man.getDB();
    db.exec("delete from object;");
    db.exec("delete from object_generalization;");
    db.exec("delete from object_composition;");
}
