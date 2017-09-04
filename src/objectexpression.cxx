#include "objectexpression.hxx"

ObjectExpression::ObjectExpression(std::string object_name)
    , m_name(std::move(object_name))
{}
