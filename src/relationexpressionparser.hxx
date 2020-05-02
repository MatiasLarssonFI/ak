#ifndef RELATIONEXPRESSIONPARSER_HXX
#define RELATIONEXPRESSIONPARSER_HXX

#include <string>
#include <vector>

#include "irelationexpression.hxx"
#include "objectexpression.hxx"
#include "alias.hxx"

class RelationExpressionParser
{
    public:
        RelationExpressionParser();
        uptr<IRelationExpression> fromLine(std::string line);
    private:
        template <class T>
        uptr<IRelationExpression> makeExpression(ObjectExpression subject, std::vector<ObjectExpression> rhs_operands) const {
            return uptr<IRelationExpression>(new T(std::move(subject), std::move(rhs_operands)));
        }
};

#endif // RELATIONEXPRESSIONPARSER_HXX
