#ifndef DBCONFIG_HXX
#define DBCONFIG_HXX

#include <string>


//! Singleton; Database configuration representation
class DBConfig
{
    public:
        static DBConfig& getInstance();
        const std::string& filename() const;

        DBConfig(DBConfig const &) = delete;
        DBConfig& operator=(DBConfig const &) = delete;

        static std::string db_filename;
    protected:
        DBConfig(std::string filename);
    private:
        std::string m_filename;
};

#endif // DBCONFIG_HXX
