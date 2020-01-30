#ifndef SQLITEDB_H
#define SQLITEDB_H

#include <string>

#include <sqlite3.h>

class SQLiteDB
{
    sqlite3 *db;
    std::string name;

public:
    SQLiteDB(std::string n) : name{n}
    {
        sqlite3_open(name.c_str(),&db);
    }

    ~SQLiteDB()
    {
        sqlite3_close(db);
    }
};

#endif // SQLITEDB_H
