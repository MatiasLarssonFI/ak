#ifndef GENERALIZATIONRELATIONEXPRESSION_HXX
#define GENERALIZATIONRELATIONEXPRESSION_HXX

#include <vector>

#include "irelationexpression.hxx"
#include "objectexpression.hxx"
#include "relationexpressionsavevisitor.hxx"
#include "alias.hxx"


class GeneralizationRelationExpression : public IRelationExpression
{
    public:
        void GeneralizationRelationExpression(ObjectExpression generalization, std::vector<ObjectExpression> elems);
        void accept(RelationExpressionSaveVisitor &);

        //! Returns the composite object for the expression.
        ObjectExpression const & generalization() const { return m_gen; }:

        //! Returns the
        std::vector<ObjectExpression> const & elements() const { return m_elems; }:
    private:
        ObjectExpression const m_gen;
        std::vector<ObjectExpression> const m_elems;
};

#endif // GENERALIZATIONRELATIONEXPRESSION_HXX
