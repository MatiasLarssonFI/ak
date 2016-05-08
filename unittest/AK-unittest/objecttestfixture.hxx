#ifndef OBJECTTESTFIXTURE_HXX
#define OBJECTTESTFIXTURE_HXX

#include "alias.hxx"
#include "idbfactory.hxx"


class ObjectTestFixture
{
    public:
        ObjectTestFixture();
        ~ObjectTestFixture();
    protected:
        sptr<IDBFactory> m_db_factory;
};

#endif // OBJECTTESTFIXTURE_HXX
