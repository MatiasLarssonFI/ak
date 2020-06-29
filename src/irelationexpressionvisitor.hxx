#ifndef IRELATIONEXPRESSIONVISITOR_HXX
#define IRELATIONEXPRESSIONVISITOR_HXX

class IRelationExpressionVisitor
{
    public:
        IRelationExpressionVisitor() = default;

        virtual ~IRelationExpressionVisitor() = default;

        virtual void visit(class GeneralizationRelationExpression & expr) = 0;
        virtual void visit(class CompositionRelationExpression & expr) = 0;
        virtual void visit(class ObjectExpression & expr) = 0;

        // rule of zero. These must be defaulted since the destructor is user-defined.
        IRelationExpressionVisitor(IRelationExpressionVisitor const &) = default;
        IRelationExpressionVisitor(IRelationExpressionVisitor &&) = default;
        IRelationExpressionVisitor& operator=(IRelationExpressionVisitor const &) = default;
        IRelationExpressionVisitor& operator=(IRelationExpressionVisitor &&) = default;
};

#endif // IRELATIONEXPRESSIONVISITOR_HXX
