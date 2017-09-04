#ifndef IRELATIONEXPRESSION_HXX
#define IRELATIONEXPRESSION_HXX

#include "relationexpressionsavevisitor.hxx"
#include "alias.hxx"

//! Interface for relation expressions.
class IRelationExpression
{
    public:
        //! Accpets the visitor that saves the expression as objects.
        void accept(RelationExpressionSaveVisitor &) = 0;

        ~IRelationExpression() = default;
        // rule of zero. These must be defaulted since the destructor is user-defined.
        IRelationExpression(IRelationExpression const &) = default;
        IRelationExpression(IRelationExpression &&) = default;
        IRelationExpression& operator=(IRelationExpression const &) = default;
        IRelationExpression& operator=(IRelationExpression &&) = default;
};

#endif // IRELATIONEXPRESSION_HXX
