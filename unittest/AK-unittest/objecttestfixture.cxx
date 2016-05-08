#include "objecttestfixture.hxx"

#include "dbfactoryutil.hxx"


ObjectTestFixture::ObjectTestFixture()
    : m_db_factory(ak_util::getDBFactory())
{
    //ctor
}

ObjectTestFixture::~ObjectTestFixture()
{
    //dtor
}
