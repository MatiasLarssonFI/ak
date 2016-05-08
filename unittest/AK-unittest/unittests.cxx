#include "UnitTest++/UnitTest++.h"

#include "objecttestfixture.hxx"
#include "alias.hxx"
#include "dbconfig.hxx"


TEST_FIXTURE(ObjectTestFixture, OBJECT_INSTANCE)
{
    uptr<IDBObject> obj = m_db_factory->getDBObject("test object");
    CHECK(!obj->exists());
    CHECK_EQUAL("test object", obj->name());
    CHECK_EQUAL(0, obj->id());
}


TEST_FIXTURE(ObjectTestFixture, OBJECT_SAVE_SUCCESS)
{
    uptr<IDBObject> obj = m_db_factory->getDBObject("test object");
    REQUIRE CHECK(!obj->exists());
    obj->create();
    CHECK(obj->exists());
    CHECK(obj->id() > 0);
}


int main(int argc, const char * argv[]) {
    if (argc == 2) {
        DBConfig::db_filename = argv[1];
        return UnitTest::RunAllTests();
    } else {
        errstream << "Usage: " << argv[0] << " [database filename]" << std::endl;
    }
}
