#include "generalizationrelationexpression.hxx"
#include "alias.hxx"

GeneralizationRelationExpression::GeneralizationRelationExpression(ObjectExpression generalization, std::vector<ObjectExpression> elements)
    : m_gen(std::move(generalization))
    , m_elems(std::move(elements))
{}


void GeneralizationRelationExpression::accept(IRelationExpressionVisitor & visitor) {
    visitor.visit(*this);
}
