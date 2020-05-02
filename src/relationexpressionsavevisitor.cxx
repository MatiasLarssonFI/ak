#include "relationexpressionsavevisitor.hxx"

#include <vector>

#include "alias.hxx"
#include "global_objects.hxx"
#include "objectexpression.hxx"

void RelationExpressionSaveVisitor::visit(GeneralizationRelationExpression & expr) {
    for (auto & elem : expr.elements()) {
        this->visit(elem);
        db_inst_man.getDBFactory()->getDBObject(elem)->addGeneralization(expr.generalization().objectName());
    }
}


void RelationExpressionSaveVisitor::visit(CompositionRelationExpression & expr) {
    this->visit(expr.composite());
    uptr<IDBObject> composite = db_inst_man.getDBFactory()->getDBObject(expr.composite());
    for (auto & elem : expr.components()) {
        composite->addComponent(elem.objectName());
    }
}


void RelationExpressionSaveVisitor::visit(ObjectExpression & expr) {
    uptr<IDBObject> obj = db_inst_man.getDBFactory()->getDBObject(expr);
    if (!obj->exists()) {
        obj->create();
    }
}
