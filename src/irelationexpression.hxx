#ifndef IRELATIONEXPRESSION_HXX
#define IRELATIONEXPRESSION_HXX


//! Interface for relation write operations.
class IRelationExpression
{
    public:
        void accept(uptr<RelationExpressionVisitor>) = 0;
};

#endif // IRELATIONEXPRESSION_HXX
