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

        virtual bool hasNext() const = 0;
};

#endif // IDBCURSOR_HXX
