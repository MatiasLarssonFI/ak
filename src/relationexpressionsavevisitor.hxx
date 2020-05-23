#ifndef RELATIONEXPRESSIONSAVEVISITOR_HXX
#define RELATIONEXPRESSIONSAVEVISITOR_HXX

#include "irelationexpressionvisitor.hxx"

#include "generalizationrelationexpression.hxx"
#include "compositionrelationexpression.hxx"
#include "objectexpression.hxx"
#include "dbinstancemanager.hxx"

//! Visitor that saves RelationExpressions
class RelationExpressionSaveVisitor : public IRelationExpressionVisitor
{
    public:
        RelationExpressionSaveVisitor(DBInstanceManager & db_inst_man);

        void visit(GeneralizationRelationExpression & expr);
        void visit(CompositionRelationExpression & expr);
        void visit(ObjectExpression & expr);
    private:
        DBInstanceManager & m_db_inst_man;
};

#endif // RELATIONEXPRESSIONSAVEVISITOR_HXX
