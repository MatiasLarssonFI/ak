#ifndef GENERALIZATIONRELATIONEXPRESSION_HXX
#define GENERALIZATIONRELATIONEXPRESSION_HXX

#include <vector>

#include "irelationexpression.hxx"
#include "objectexpression.hxx"
#include "irelationexpressionvisitor.hxx"
#include "alias.hxx"


class GeneralizationRelationExpression : public IRelationExpression
{
    public:
        GeneralizationRelationExpression(ObjectExpression generalization, std::vector<ObjectExpression> elems);
        void accept(IRelationExpressionVisitor &);

        //! Returns the generalization object for the expression.
        ObjectExpression & generalization() { return m_gen; };

        //! Returns the generalized objects for the expression.
        std::vector<ObjectExpression> & elements() { return m_elems; };
    private:
        ObjectExpression m_gen;
        std::vector<ObjectExpression> m_elems;
};

#endif // GENERALIZATIONRELATIONEXPRESSION_HXX
