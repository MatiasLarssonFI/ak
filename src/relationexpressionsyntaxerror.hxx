#ifndef RELATIONEXPRESSIONSYNTAXERROR_HXX
#define RELATIONEXPRESSIONSYNTAXERROR_HXX

#include <stdexcept>


class RelationExpressionSyntaxError : public std::runtime_error
{
    public:
        explicit RelationExpressionSyntaxError(const std::string& what_arg)
            : std::runtime_error(what_arg)
        {}
};

#endif // RELATIONEXPRESSIONSYNTAXERROR_HXX
