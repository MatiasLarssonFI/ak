#include "dbobject.hxx"

#include <utility>


DBObject::DBObject(std::string name)
    : m_name(std::move(name))
{}


const std::string& DBObject::name() const {
    return m_name;
}
