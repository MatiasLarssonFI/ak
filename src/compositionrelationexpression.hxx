#ifndef COMPOSITIONRELATIONEXPRESSION_HXX
#define COMPOSITIONRELATIONEXPRESSION_HXX

#include <vector>

#include "irelationexpression.hxx"
#include "objectexpression.hxx"
#include "irelationexpressionvisitor.hxx"
#include "alias.hxx"


class CompositionRelationExpression : public IRelationExpression
{
    public:
        CompositionRelationExpression(ObjectExpression composite, std::vector<ObjectExpression> components);
        void accept(IRelationExpressionVisitor &);

        //! Returns the composite object for the expression.
        ObjectExpression & composite() { return m_composite; };

        //! Returns the component objects for the expression.
        std::vector<ObjectExpression> & components() { return m_components; };
    private:
        ObjectExpression m_composite;
        std::vector<ObjectExpression> m_components;
};

#endif // COMPOSITIONRELATIONEXPRESSION_HXX
