#include "objectexpression.hxx"

ObjectExpression::ObjectExpression(std::string object_name)
    : m_name(std::move(object_name))
{}

void ObjectExpression::accept(IRelationExpressionVisitor & visitor) {
    visitor.visit(*this);
}
