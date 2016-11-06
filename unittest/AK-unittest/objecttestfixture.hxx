#ifndef OBJECTTESTFIXTURE_HXX
#define OBJECTTESTFIXTURE_HXX

#include "alias.hxx"
#include "dbinstancemanager.hxx"


class ObjectTestFixture
{
    public:
        ObjectTestFixture();
        ~ObjectTestFixture();
    protected:
        DBInstanceManager m_db_inst_man;
        uptr<IDBFactory> const & m_db_factory;
};

#endif // OBJECTTESTFIXTURE_HXX
