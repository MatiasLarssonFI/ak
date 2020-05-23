#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "alias.hxx"
#include "dbconfig.hxx"
#include "dbinstancemanager.hxx"
#include "sqlite3dbcursor.hxx"
#include "streaminterface.hxx"


int main(int argc, char *argv[]) {

    if (argc == 2) {
        try {
            DBConfig::db_filename = argv[1];
            DBInstanceManager db_inst_man;
            StreamInterface sif{std::cin, std::cout, db_inst_man};
            sif.listen();
        } catch (std::exception const & e) {
            errstream << "Error: " << e.what() << std::endl;
        }
    } else {
        errstream << "Usage: " << argv[0] << " [database filename]" << std::endl;
    }
}
