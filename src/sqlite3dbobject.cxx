#include "sqlite3dbobject.hxx"

#include <utility>


SQLite3DBObject::SQLite3DBObject(std::string name)
    : m_name(std::move(name))
{}


const std::string& SQLite3DBObject::name() const {
    return m_name;
}
