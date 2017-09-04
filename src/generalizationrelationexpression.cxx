#include "relationexpression.hxx"
#include "alias.hxx"

void GeneralizationRelationExpression::GeneralizationRelationExpression(ObjectExpression generalization, std::vector<ObjectExpression> elements)
    : m_gen(std::move(generalization))
    , m_elems(std::move(elements))
{}


void GeneralizationRelationExpression::accept(RelationExpressionSaveVisitor & visitor) {
    visitor.visit(*this);
}
