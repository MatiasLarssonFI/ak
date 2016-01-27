#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

#include "alias.hxx"
#include "sqlite3dbcursor.hxx"


int main(int argc, char *argv[]) {

    // Open a database file
    SQLite::Database    db(argv[1]);

    // Compile a SQL query, containing one parameter (index 1)
    SQLite::Statement   query(db, "SELECT * FROM object");
    uptr<IDBCursor<std::string>> p_cursor(new SQLite3DBCursor<std::string>(query, [] (std::vector<SQLite::Column> cols) -> std::string {
        const auto it = std::find(cols.begin(), cols.end(), [] (SQLite::Column const & col) {
            return std::string(col.getName()) == "name";
        });
        if (it != cols.end()) {
            return it->getName();
        }
        return "";
    }));

    while (p_cursor->hasNext()) {
        std::cout << p_cursor->next() << std::endl;
    }
}
