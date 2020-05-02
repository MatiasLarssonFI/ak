#ifndef OBJECTEXPRESSION_HXX
#define OBJECTEXPRESSION_HXX

#include <string>

#include "irelationexpression.hxx"

class ObjectExpression : public IRelationExpression
{
    public:
        ObjectExpression(std::string object_name);
        std::string const & objectName() const { return m_name; }

        void accept(IRelationExpressionVisitor &);
    private:
        std::string m_name;
};

#endif // OBJECTEXPRESSION_HXX
