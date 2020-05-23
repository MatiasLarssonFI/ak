#include "UnitTest++/UnitTest++.h"

#include <string>
#include <stdexcept>
#include <algorithm> // find

#include "objecttestfixture.hxx"
#include "ak_mock.hxx"

#include "alias.hxx"
#include "dbconfig.hxx"
#include "idbobject.hxx"


// initialization
TEST_FIXTURE(ObjectTestFixture, OBJECT_INSTANCE)
{
    uptr<IDBObject> obj = m_db_factory->getDBObject("test object");
    CHECK(!obj->exists());
    CHECK_EQUAL("test object", obj->name());
    CHECK_EQUAL(0, obj->id());
}


// save
TEST_FIXTURE(ObjectTestFixture, OBJECT_SAVE_SUCCESS)
{
    uptr<IDBObject> obj = m_db_factory->getDBObject("test object");
    REQUIRE CHECK(!obj->exists());
    obj->create();
    CHECK(obj->exists());
    CHECK(obj->id() > 0);
}


// one generalization
TEST_FIXTURE(ObjectTestFixture, OBJECT_GEN_ADD_ONE)
{
    constexpr auto str_ms = "Motor ship";
    uptr<IDBObject> grace = m_db_factory->getDBObject("Viking Grace");
    grace->create();
    REQUIRE CHECK(grace->exists()); // just make sure that object was created, pre-requisite of test

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


// one component
TEST_FIXTURE(ObjectTestFixture, OBJECT_COM_ADD_ONE)
{
    constexpr auto str_engine = "Ship engine";
    uptr<IDBObject> ship = m_db_factory->getDBObject("Motor Ship");
    REQUIRE CHECK(!ship->exists()); // just make sure that object does NOT exist, pre-requisite of test

    ship->create();
    ship->addComponent(str_engine);

    uptr<IDBObject> engine = m_db_factory->getDBObject(str_engine);
    REQUIRE CHECK(engine->exists());

    uptr<IDBObject::DBCursor> com_cursor = ship->componentCursor();
    int com_count = 0;

    while (com_cursor->hasNext()) {
        com_count++;
        CHECK_EQUAL(str_engine, com_cursor->next()->name());
    }

    CHECK_EQUAL(1, com_count);
}


// many components
TEST_FIXTURE(ObjectTestFixture, OBJECT_COM_ADD_MANY)
{
    const std::vector<std::string> components { "Ship engine", "Rudder", "Deck", "Lifeboat" };
    uptr<IDBObject> ship = m_db_factory->getDBObject("Motor Ship");

    ship->create();
    for (auto const & str_com : components) {
        ship->addComponent(str_com);
        uptr<IDBObject> com = m_db_factory->getDBObject(str_com);
        REQUIRE CHECK(com->exists());
    }

    uptr<IDBObject::DBCursor> com_cursor = ship->componentCursor();
    int com_count = 0;

    while (com_cursor->hasNext()) {
        com_count++;
        CHECK(std::find(components.begin(), components.end(), com_cursor->next()->name()) != components.end());
    }

    CHECK_EQUAL(components.size(), com_count);
}


// save duplicate (error handling)
TEST_FIXTURE(ObjectTestFixture, OBJECT_SAVE_DUPLICATE_ERROR)
{
    uptr<IDBObject> obj = m_db_factory->getDBObject("test object");
    REQUIRE CHECK(!obj->exists());
    obj->create();
    bool had_exception = false;
    try {
        obj->create();
    } catch (std::logic_error const & e) {
        had_exception = true;
    }
    CHECK(had_exception);
}


// parser: one new object
TEST_FIXTURE(ObjectTestFixture, PARSER_ONE_NEW_OBJECT)
{
    uptr<IRelationExpression> expr = m_relexp_parser.fromLine("rocket");
    REQUIRE CHECK((bool)expr);

    RelationExpressionAssertTypeVisitor visitor{RelationExpressionAssertTypeVisitor::Type::Object};
    expr->accept(visitor); // will make the CHECK
}


// parser: generalization
TEST_FIXTURE(ObjectTestFixture, PARSER_GENERALIZATION)
{
    uptr<IRelationExpression> expr = m_relexp_parser.fromLine("airplane is vehicle");
    REQUIRE CHECK((bool)expr);

    RelationExpressionAssertTypeVisitor visitor{RelationExpressionAssertTypeVisitor::Type::Generalization};
    expr->accept(visitor); // will make the CHECK
}


// parser: composition
TEST_FIXTURE(ObjectTestFixture, PARSER_COMPOSITION)
{
    uptr<IRelationExpression> expr = m_relexp_parser.fromLine("airplane has engine");
    REQUIRE CHECK((bool)expr);

    RelationExpressionAssertTypeVisitor visitor{RelationExpressionAssertTypeVisitor::Type::Composition};
    expr->accept(visitor); // will make the CHECK
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
