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
        GeneralizationRelationExpression(ObjectExpression subject, std::vector<ObjectExpression> generalizations);
        void accept(IRelationExpressionVisitor &);

        //! Returns the generalized object for the expression.
        ObjectExpression & subject() { return m_subject; };

        //! Returns the generalization objects for the expression.
        std::vector<ObjectExpression> & elements() { return m_gens; };
    private:
        ObjectExpression m_subject;
        std::vector<ObjectExpression> m_gens;
};

#endif // GENERALIZATIONRELATIONEXPRESSION_HXX
