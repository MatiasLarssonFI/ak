#include "relationexpression.hxx"
#include "alias.hxx"

void GeneralizationRelationExpression::GeneralizationRelationExpression(uptr<ObjectExpression> composite, std::vector<ObjectExpression> components)
    : m_composite(std::move(composite))
    , m_components(std::move(components))
{}
