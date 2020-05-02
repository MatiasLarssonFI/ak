#ifndef IRELATIONEXPRESSION_HXX
#define IRELATIONEXPRESSION_HXX

#include "irelationexpressionvisitor.hxx"
#include "alias.hxx"

//! Interface for relation expressions.
class IRelationExpression
{
    public:
        IRelationExpression() = default;
        virtual void accept(IRelationExpressionVisitor &) = 0;

        virtual ~IRelationExpression() = default;
        // rule of zero. These must be defaulted since the destructor is user-defined.
        IRelationExpression(IRelationExpression const &) = default;
        IRelationExpression(IRelationExpression &&) = default;
        IRelationExpression& operator=(IRelationExpression const &) = default;
        IRelationExpression& operator=(IRelationExpression &&) = default;
};

#endif // IRELATIONEXPRESSION_HXX
