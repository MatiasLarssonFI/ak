#ifndef IDBCURSOR_HXX
#define IDBCURSOR_HXX


template <class T>
class IDBCursor
{
    public:
        IDBCursor() = default;

        //! Returns the next object under cursor
        /*!
         * \throw std::runtime_error If there are no more rows in squence
         */
        virtual T next() = 0;


        //! Returns true if next() will succeed.
        virtual bool hasNext() const = 0;


        virtual ~IDBCursor() = default;
        // rule of zero. These must be defaulted since the destructor is user-defined.
        IDBCursor(IDBCursor const &) = default;
        IDBCursor(IDBCursor &&) = default;
        IDBCursor& operator=(IDBCursor const &) = default;
        IDBCursor& operator=(IDBCursor &&) = default;
};

#endif // IDBCURSOR_HXX
