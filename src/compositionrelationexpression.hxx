#ifndef COMPOSITIONRELATIONEXPRESSION_HXX
#define COMPOSITIONRELATIONEXPRESSION_HXX

#include <vector>

#include "irelationexpression.hxx"
#include "objectexpression.hxx"
#include "relationexpressionsavevisitor.hxx"
#include "alias.hxx"


class CompositionRelationExpression : public IRelationExpression
{
    public:
        void CompositionRelationExpression(ObjectExpression composite, std::vector<ObjectExpression> components);
        void accept(RelationExpressionSaveVisitor &);

        //! Returns the composite object for the expression.
        ObjectExpression const & composite() const { return m_composite; }:

        //! Returns the component objects for the expression.
        std::vector<ObjectExpression> const & components() const { return m_components; }:
    private:
        ObjectExpression const m_composite;
        std::vector<ObjectExpression> const m_components;
};

#endif // COMPOSITIONRELATIONEXPRESSION_HXX
