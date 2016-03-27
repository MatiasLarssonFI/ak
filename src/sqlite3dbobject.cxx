#include "sqlite3dbobject.hxx"

#include <utility>

#include "dbconfig.hxx"
#include "sqlite3dbcursor.hxx"
#include "alias.hxx"


SQLite3DBObject::SQLite3DBObject(std::string name)
    : m_name(std::move(name))
    , m_db(_getDBInstance())
    , m_id(0)
{
    // try to get object id
    t_statement query(m_db, "SELECT id FROM object where name = ?");
    query.bind(1, m_name);
    if (query.executeStep()) {
        m_id = (int)query.getColumn(0);
    }
}


const std::string& SQLite3DBObject::name() const {
    return m_name;
}


bool SQLite3DBObject::exists() const {
    return m_id > 0;
}


void SQLite3DBObject::create() {
    if (!exists()) {
        t_statement query(m_db, "INSERT INTO object name VALUES(?)");
        query.bind(1, m_name);
        query.exec();
    } else {
        throw std::logic_error(std::string("'") + m_name + "' already exists");
    }
}


void SQLite3DBObject::addComponent(std::string component_name) const {
    //TBD
};


void SQLite3DBObject::addGeneralization(std::string gen_name) const {
    //TBD
};


uptr<IDBObject::DBCursor> SQLite3DBObject::componentCursor() const {
    t_statement query(m_db, "SELECT o_com.name FROM object"
                            " inner join object_composition c on c.subject = ?" // N to 1
                            " inner join object o_com on o_com.id = c.component"); // 1 to 1
    query.bind(1, (int)m_id);
    return _cursor(query);
};


uptr<IDBObject::DBCursor> SQLite3DBObject::generalizationCursor() const {
   t_statement query(m_db, "SELECT o_gen.name FROM object"
                            " inner join object_generalization g on g.subject = ?" // N to 1
                            " inner join object o_gen on o_gen.id = g.generalization"); // 1 to 1
    query.bind(1, (int)m_id);
    return _cursor(query);
};


uptr<IDBObject::DBCursor> SQLite3DBObject::_cursor(SQLite3DBObject::t_statement& stm) const {
    return uptr<IDBObject::DBCursor> (new SQLite3DBCursor<uptr<IDBObject>>(stm, [] (std::vector<SQLite::Column> cols) {
        return uptr<IDBObject>(new SQLite3DBObject(cols[0].getText()));
    }));
};


SQLite::Database& SQLite3DBObject::_getDBInstance() const {
    static t_db db(DBConfig::getInstance().filename());
    return db;
}
