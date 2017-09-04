#ifndef OBJECTEXPRESSION_HXX
#define OBJECTEXPRESSION_HXX

#include <string>


class ObjectExpression
{
    public:
        ObjectExpression(std::string object_name);
        std::string const & objectName() const { return m_name; }
    private:
        std::string const m_name;
};

#endif // OBJECTEXPRESSION_HXX
