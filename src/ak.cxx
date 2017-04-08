#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "alias.hxx"
#include "dbconfig.hxx"
#include "dbinstancemanager.hxx"
#include "sqlite3dbcursor.hxx"


int main(int argc, char *argv[]) {

    if (argc == 2) {
        try {
            DBConfig::db_filename = argv[1];
            DBInstanceManager db_inst_man;
            SQLite::Database& db = db_inst_man.getDB();

            uptr<SQLite::Statement> p_query(new SQLite::Statement(db, "SELECT name FROM object"));
            uptr<IDBCursor<std::string>> p_cursor(new SQLite3DBCursor<std::string>(std::move(p_query), [] (std::vector<SQLite::Column> cols) {
                return cols[0].getText();
            }));

            while (p_cursor->hasNext()) {
                std::cout << p_cursor->next() << std::endl;
            }
        } catch (std::exception const & e) {
            errstream << "Error: " << e.what() << std::endl;
        }
    } else {
        errstream << "Usage: " << argv[0] << " [database filename]" << std::endl;
    }
}
