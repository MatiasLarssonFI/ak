#ifndef STREAMINTERFACE_HXX
#define STREAMINTERFACE_HXX

#include "relationexpressionparser.hxx"
#include "dbinstancemanager.hxx"

#include <iostream>


class StreamInterface
{
    public:
        StreamInterface(std::istream& in, std::ostream& out, DBInstanceManager& db_inst_man);

        //! Listen for commands.
        /*!
         * Blocks execution and listens for commands.
         */
        void listen();

        virtual ~StreamInterface() {}
    private:
        //! Handle a line from input
        void lineHandler(std::string);

        std::istream& m_in;
        std::ostream& m_out;

        RelationExpressionParser m_relexp_parser;
        DBInstanceManager& m_db_inst_man;
};

#endif // STREAMINTERFACE_HXX
