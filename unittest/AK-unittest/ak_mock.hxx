#ifndef AK_MOCK_HXX
#define AK_MOCK_HXX

#include "irelationexpressionvisitor.hxx"

#include "generalizationrelationexpression.hxx"
#include "compositionrelationexpression.hxx"
#include "objectexpression.hxx"

#include "UnitTest++/UnitTest++.h"

//! Mock visitor, used by unit tests.
class RelationExpressionAssertTypeVisitor : public IRelationExpressionVisitor
{
    public:
        enum Type {Generalization, Composition, Object};

        RelationExpressionAssertTypeVisitor(Type expectedType) : m_expectedType(expectedType)
        {}

        void visit(GeneralizationRelationExpression & expr) {
            (void)expr;
            CHECK(m_expectedType == Generalization);
        }

        void visit(CompositionRelationExpression & expr) {
            (void)expr;
            CHECK(m_expectedType == Composition);
        }

        void visit(ObjectExpression & expr) {
            (void)expr;
            CHECK(m_expectedType == Object);
        }

    private:
        Type m_expectedType;
};

#endif // AK_MOCK_HXX
