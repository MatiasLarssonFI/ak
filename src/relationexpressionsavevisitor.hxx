#ifndef RELATIONEXPRESSIONSAVEVISITOR_HXX
#define RELATIONEXPRESSIONSAVEVISITOR_HXX


//! Visitor that saves RelationExpressions
class RelationExpressionSaveVisitor
{
    public:
        void visit(GeneralizationRelationExpression const & expr);
        void visit(CompositionRelationExpression const & expr);
};

#endif // RELATIONEXPRESSIONSAVEVISITOR_HXX
