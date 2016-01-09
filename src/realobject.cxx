#include "dbobject.hxx"

#include <utility>


RealObject::RealObject(std::string name)
    : m_name(std::move(name))
{}


const std::string& RealObject::name() const {
    return m_name;
}
