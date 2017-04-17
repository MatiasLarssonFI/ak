#include "UnitTest++/UnitTest++.h"

#include <string>
#include <stdexcept>

#include "objecttestfixture.hxx"
#include "alias.hxx"
#include "dbconfig.hxx"
#include "idbobject.hxx"


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


TEST_FIXTURE(ObjectTestFixture, OBJECT_GEN_ADD)
{
    constexpr auto str_ms = "Motor ship";
    uptr<IDBObject> grace = m_db_factory->getDBObject("Viking Grace");
    grace->create();
    REQUIRE CHECK(grace->exists()); // just make sure that object is created, not really part of test

    grace->addGeneralization(str_ms);

    uptr<IDBObject> ms = m_db_factory->getDBObject(str_ms);
    REQUIRE CHECK(ms->exists());

    uptr<IDBObject::DBCursor> gen_cursor = grace->generalizationCursor();
    int gen_count = 0;

    while (gen_cursor->hasNext()) {
        gen_count++;
        CHECK_EQUAL(str_ms, gen_cursor->next()->name());
    }

    CHECK_EQUAL(1, gen_count);
}


int main(int argc, const char * argv[]) {
    if (argc == 2) {
        try {
            DBConfig::db_filename = argv[1];
            return UnitTest::RunAllTests();
        } catch (std::exception const & e) {
            errstream << "Error: " << e.what() << std::endl;
        }
    } else {
        errstream << "Usage: " << argv[0] << " [database filename]" << std::endl;
    }
}
