#include "sqlite3dbobject.hxx"

#include <utility>
#include <stdexcept>

#include "sqlite3dbcursor.hxx"
#include "alias.hxx"


SQLite3DBObject::SQLite3DBObject(std::string name, t_db& db)
    : m_name(std::move(name))
    , m_db(db)
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


unsigned SQLite3DBObject::id() const {
    return m_id;
}


bool SQLite3DBObject::exists() const {
    return m_id > 0;
}


void SQLite3DBObject::create() {
    if (!exists()) {
        t_statement query(m_db, "INSERT INTO object (name) VALUES(?)");
        query.bind(1, m_name);
        query.exec();
        m_id = m_db.getLastInsertRowid();
    } else {
        throw std::logic_error(std::string("\"") + m_name + "\" already exists");
    }
}


void SQLite3DBObject::addComponent(std::string component_name) const {
    SQLite3DBObject com(component_name, m_db);
    if (!com.exists()) {
        com.create();
    }

    t_statement query(m_db, "INSERT INTO object_composition (subject, component) VALUES(?, ?)");
    query.bind(1, (int)m_id);
    query.bind(2, (int)com.id());
    query.exec();
}


void SQLite3DBObject::addGeneralization(std::string gen_name) const {
    SQLite3DBObject gen(gen_name, m_db);
    if (!gen.exists()) {
        gen.create();
    }

    t_statement query(m_db, "INSERT INTO object_generalization (subject, generalization) VALUES(?, ?)");
    query.bind(1, (int)m_id);
    query.bind(2, (int)gen.id());
    query.exec();
}


uptr<IDBObject::DBCursor> SQLite3DBObject::componentCursor() const {
    uptr<t_statement> p_query(
                        new t_statement(m_db, "SELECT object.name FROM object_composition oc"
                            " inner join object on object.id = oc.component" // 1 to 1
                            " where oc.subject = ?")
                    );
    p_query->bind(1, (int)m_id);
    return _cursor(std::move(p_query));
}


uptr<IDBObject::DBCursor> SQLite3DBObject::generalizationCursor() const {
    uptr<t_statement> p_query(
                        new t_statement(m_db, "SELECT object.name FROM object_generalization og"
                            " inner join object on object.id = og.generalization" // 1 to 1
                            " where og.subject = ?")
                    );
    p_query->bind(1, (int)m_id);
    return _cursor(std::move(p_query));
}


uptr<IDBObject::DBCursor> SQLite3DBObject::_cursor(uptr<SQLite3DBObject::t_statement> p_stm) const {
    t_db& db = m_db;
    return uptr<IDBObject::DBCursor> (new SQLite3DBCursor<uptr<IDBObject>>(std::move(p_stm), [&db] (std::vector<SQLite::Column> cols) {
        return uptr<IDBObject>(new SQLite3DBObject(cols[0].getText(), db));
    }));
}
