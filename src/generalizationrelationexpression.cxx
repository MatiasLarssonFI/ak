#include "generalizationrelationexpression.hxx"
#include "alias.hxx"

GeneralizationRelationExpression::GeneralizationRelationExpression(ObjectExpression subject, std::vector<ObjectExpression> generalizations)
    : m_subject(std::move(subject))
    , m_gens(std::move(generalizations))
{}


void GeneralizationRelationExpression::accept(IRelationExpressionVisitor & visitor) {
    visitor.visit(*this);
}
