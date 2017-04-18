#ifndef IDBCURSOR_HXX
#define IDBCURSOR_HXX


template <class T>
class IDBCursor
{
    public:
        //! Returns the next object under cursor
        /*!
         * \throw std::runtime_error If there are no more rows in squence
         */
        virtual T next() = 0;


        //! Returns true if next() will succeed.
        virtual bool hasNext() const = 0;


        virtual ~IDBCursor() {}
};

#endif // IDBCURSOR_HXX
