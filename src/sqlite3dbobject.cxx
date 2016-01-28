#include "sqlite3dbobject.hxx"

#include <utility>


SQLite3DBObject::SQLite3DBObject(std::string name)
    : m_name(std::move(name))
{}


const std::string& SQLite3DBObject::name() const {
    return m_name;
}


void SQLite3DBObject::addProperty(std::string property_name) const {
    //TBD
};
void SQLite3DBObject::addGeneralization(std::string gen_name) const {
    //TBD
};

uptr<IDBObject::DBCursor> SQLite3DBObject::propertyCursor() const {
    //TBD
};
uptr<IDBObject::DBCursor> SQLite3DBObject::generalizationCursor() const {
    //TBD
};
