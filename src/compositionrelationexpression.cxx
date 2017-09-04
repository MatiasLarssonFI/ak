#include "relationexpression.hxx"
#include "alias.hxx"

void CompositionRelationExpression::GeneralizationRelationExpression(ObjectExpression composite, std::vector<ObjectExpression> components)
    : m_composite(std::move(composite))
    , m_components(std::move(components))
{}


void CompositionRelationExpression::accept(RelationExpressionSaveVisitor & visitor) {
    visitor.visit(*this);
}
