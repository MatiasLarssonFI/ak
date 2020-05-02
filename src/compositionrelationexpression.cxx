#include "compositionrelationexpression.hxx"

#include "alias.hxx"

CompositionRelationExpression::CompositionRelationExpression(ObjectExpression composite, std::vector<ObjectExpression> components)
    : m_composite(std::move(composite))
    , m_components(std::move(components))
{}


void CompositionRelationExpression::accept(IRelationExpressionVisitor & visitor) {
    visitor.visit(*this);
}
