#include "dbconfig.hxx"


std::string DBConfig::db_filename;


DBConfig& DBConfig::getInstance() {
    static DBConfig inst(DBConfig::db_filename);
    return inst;
}


const std::string& DBConfig::filename() const {
    return m_filename;
}


DBConfig::DBConfig(std::string filename)
    : m_filename(std::move(filename))
{}
