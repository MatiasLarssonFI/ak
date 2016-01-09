#ifndef IDBCURSOR_HXX
#define IDBCURSOR_HXX


template <class T>
class IDBCursor
{
    public:
        virtual T next() = 0;
        virtual bool hasNext() const;
};

#endif // IDBCURSOR_HXX
