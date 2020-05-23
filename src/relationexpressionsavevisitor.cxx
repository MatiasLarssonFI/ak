#include "relationexpressionsavevisitor.hxx"

#include <vector>

#include "alias.hxx"
#include "objectexpression.hxx"

RelationExpressionSaveVisitor::RelationExpressionSaveVisitor(DBInstanceManager & db_inst_man)
    : m_db_inst_man(db_inst_man)
{}

void RelationExpressionSaveVisitor::visit(GeneralizationRelationExpression & expr) {
    for (auto & elem : expr.elements()) {
        this->visit(elem);
        m_db_inst_man.getDBFactory()->getDBObject(elem)->addGeneralization(expr.generalization().objectName());
    }
}


void RelationExpressionSaveVisitor::visit(CompositionRelationExpression & expr) {
    this->visit(expr.composite());
    uptr<IDBObject> composite = m_db_inst_man.getDBFactory()->getDBObject(expr.composite());
    for (auto & elem : expr.components()) {
        composite->addComponent(elem.objectName());
    }
}


void RelationExpressionSaveVisitor::visit(ObjectExpression & expr) {
    uptr<IDBObject> obj = m_db_inst_man.getDBFactory()->getDBObject(expr);
    if (!obj->exists()) {
        obj->create();
    }
}
