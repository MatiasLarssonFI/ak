#include <algorithm>
#include <sstream>
#include <string>

#include "relationexpressionparser.hxx"

#include "relationexpressionsyntaxerror.hxx"
#include "compositionrelationexpression.hxx"
#include "generalizationrelationexpression.hxx"

constexpr char composition_delim[] = "has";
constexpr char generalization_delim[] = "is";

RelationExpressionParser::RelationExpressionParser()
{}

uptr<IRelationExpression> RelationExpressionParser::fromLine(std::string line) {
    std::stringstream ss{line};
    std::vector<std::string> operands;
    do {
        std::string op;
        ss >> op;
        if (ss) {
            operands.push_back(std::move(op));
        }
    } while (ss);

    switch (operands.size()) {
        case 1:
            // just a single new object
            return uptr<IRelationExpression>{new ObjectExpression{std::move(operands[0])}};
        case 2:
            throw RelationExpressionSyntaxError("Too few operands");
        case 3:
        default:
            std::string delim = std::move(operands[1]);
            if (delim == composition_delim || delim == generalization_delim) {
                auto it = operands.begin();
                ObjectExpression subject{std::move(*it)};
                it += 2;
                std::vector<ObjectExpression> rhs_operands;
                std::transform(it, operands.end(), std::back_inserter(rhs_operands),
                                [](std::string s) -> ObjectExpression { return ObjectExpression(std::move(s)); });

                return delim == composition_delim ? makeExpression<CompositionRelationExpression>(std::move(subject), std::move(rhs_operands))
                        : makeExpression<GeneralizationRelationExpression>(std::move(subject), std::move(rhs_operands));
            }
            using namespace std::string_literals;
            // invalid delimiter
            throw RelationExpressionSyntaxError("Invalid delimiter '"s + delim + "'");
    }
}
