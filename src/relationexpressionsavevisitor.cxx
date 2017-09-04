#include "relationexpressionsavevisitor.hxx"

#include <vector>

#include "alias.hxx"
#include "global_objects.hxx"
#include "objectexpression.hxx"


void RelationExpressionSaveVisitor::visit(GeneralizationRelationExpression const & expr) {
    uptr<IDBFactory> db_f = db_inst_man.getDBFactory();
    std::string const & gen_name = expr.generalization().objectName();
    for (auto const & expr : expr.elements()) {
        db_f.getDBObject(expr.objectName()).addGeneralization(gen_name);
    }
}


void RelationExpressionSaveVisitor::visit(CompositionRelationExpression const & expr) {
    uptr<IDBFactory> db_f = db_inst_man.getDBFactory();
    uptr<IDBObject> compositor = db_f.getDBObject(expr.compositor().objectName());
    for (auto const & expr : expr.components()) {
        compositor.addComponent(expr.objectName());
    }
}
