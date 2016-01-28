#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

#include "alias.hxx"
#include "sqlite3dbcursor.hxx"


int main(int argc, char *argv[]) {

    if (argc == 2) {
        try {
            // Open a database file
            SQLite::Database db(argv[1]);

            SQLite::Statement query(db, "SELECT name FROM object");
            uptr<IDBCursor<std::string>> p_cursor(new SQLite3DBCursor<std::string>(query, [] (std::vector<SQLite::Column> cols) {
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
