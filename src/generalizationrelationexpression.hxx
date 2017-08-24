#ifndef GENERALIZATIONRELATIONEXPRESSION_HXX
#define GENERALIZATIONRELATIONEXPRESSION_HXX

#include <vector>

#include "irelationexpression.hxx"
#include "objectexpression.hxx"
#include "relationexpressionvisitor.hxx"
#include "alias.hxx"


class GeneralizationRelationExpression : public IRelationExpression
{
    public:
        void GeneralizationRelationExpression(uptr<ObjectExpression> composite, std::vector<ObjectExpression> components);
        void accept(uptr<RelationExpressionVisitor>);
    private:
        uptr<ObjectExpression> m_composite;
        std::vector<ObjectExpression> m_components;
};

#endif // GENERALIZATIONRELATIONEXPRESSION_HXX
