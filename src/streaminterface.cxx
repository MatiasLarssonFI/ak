#include <string>

#include "streaminterface.hxx"
#include "alias.hxx"
#include "irelationexpression.hxx"
#include "relationexpressionsyntaxerror.hxx"
#include "relationexpressionsavevisitor.hxx"

StreamInterface::StreamInterface(std::istream& in, std::ostream& out, DBInstanceManager & db_inst_man)
    : m_in(in)
    , m_out(out)
    , m_relexp_parser()
    , m_db_inst_man(db_inst_man)
{}


void StreamInterface::listen() {
    std::string line;
    do {
        std::getline(m_in, line);
        if (line != "q") {
            this->lineHandler(line);
        }
    } while (line != "q");
}


// A comment about the visitor:
// using the visitor allows us to easily add new expressions
// since we then only have to extend the parser implementation
// and add the expression class. The only interface modification
// will go into the visitor (that is, a new method).
// Also, the visitor allows for unified handling here for the
// polymorphic IRelationExpressions.
void StreamInterface::lineHandler(std::string line) {
    try {
        RelationExpressionSaveVisitor save_visitor(m_db_inst_man);
        uptr<IRelationExpression> expr = m_relexp_parser.fromLine(line);
        if (expr) {
            expr->accept(save_visitor);
            m_out << "Saved." << std::endl;
        }
    } catch (RelationExpressionSyntaxError const & e) {
        m_out << "Syntax error: " << e.what() << std::endl;
    } catch (std::exception const & e) {
        m_out << "Parser error: " << e.what() << std::endl;
    }
}
