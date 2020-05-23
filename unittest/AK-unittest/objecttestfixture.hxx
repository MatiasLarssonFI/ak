#ifndef OBJECTTESTFIXTURE_HXX
#define OBJECTTESTFIXTURE_HXX

#include "alias.hxx"
#include "dbinstancemanager.hxx"
#include "relationexpressionparser.hxx"


class ObjectTestFixture
{
    public:
        ObjectTestFixture();
        ~ObjectTestFixture();
    protected:
        DBInstanceManager m_db_inst_man;
        uptr<IDBFactory> const & m_db_factory;
        RelationExpressionParser m_relexp_parser;
};

#endif // OBJECTTESTFIXTURE_HXX
