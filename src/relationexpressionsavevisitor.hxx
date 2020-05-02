#ifndef RELATIONEXPRESSIONSAVEVISITOR_HXX
#define RELATIONEXPRESSIONSAVEVISITOR_HXX

#include "irelationexpressionvisitor.hxx"

#include "generalizationrelationexpression.hxx"
#include "compositionrelationexpression.hxx"
#include "objectexpression.hxx"

//! Visitor that saves RelationExpressions
class RelationExpressionSaveVisitor : public IRelationExpressionVisitor
{
    public:
        void visit(GeneralizationRelationExpression & expr);
        void visit(CompositionRelationExpression & expr);
        void visit(ObjectExpression & expr);
};

#endif // RELATIONEXPRESSIONSAVEVISITOR_HXX
