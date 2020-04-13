#include <string>

#include "streaminterface.hxx"
#include "relationexpression.hxx"
#include "alias.hxx"
#include "irelationexpression.hxx"
#include "relationexpressionsyntaxerror.hxx"
#include "relationexpressionsavevisitor.hxx"

StreamInterface::StreamInterface(std::istream& in, std::ostream& out)
    : m_in(in)
    , m_out(out)
    , m_relex_parser()
{}


void StreamInterface::listen() {
    std::string line;
    std::getline(m_in, line);
    this->lineHandler(line);
}


// A comment qabout the visitor:
// using the visitor allows us to easily add new expressions
// since we then only have to extend the parser implementation
// and add the expression class. The only interface change will
// go into the visitor.
void StreamInterface::lineHandler(std::string line) {
    try {
        RelationExpressionSaveVisitor save_visitor;
        for (uptr<IRelationExpression> expr : m_relexp_parser->from_line(line)) {
            expr->accept(save_visitor);
        }
    } catch (RelationExpressionSyntaxError const & e) {
        m_out << "Syntax error: " << e.what() << std::endl;
    } catch (std::exception const & e) {
        m_out << "Parser error: " << e.what() << std::endl;
    }
}
