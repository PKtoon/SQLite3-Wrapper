#ifndef SQLITEDB_H
#define SQLITEDB_H

#include <string>

#include <sqlite3.h>

class SQLite3DB
{
    sqlite3 *db;
    std::string name;
    std::string error;

public:
    SQLite3DB(std::string n) : name{n}
    {
        int ec = sqlite3_open(name.c_str(),&db);
        if(ec)
            error = "unable to open database";
    }

    ~SQLite3DB()
    {
        sqlite3_close(db);
    }

    sqlite3* get() { return db; }
    std::string getError() const { return error; }

    bool queryExec(std::string query, int (*callback) (void* arg,int numOfColumns, char **columnData, char **columnName) = nullptr,void* callbackArg=nullptr);
};

bool SQLite3DB::queryExec(std::string query, int (*callback) (void* arg,int numOfColumns, char **columnData, char **columnName),void* callbackArg)
{
    char* err = nullptr;
    int ec = sqlite3_exec(db,query.c_str(),callback,callbackArg,&err);

    if(ec != SQLITE_OK)
    {
        if(err)
        {
            error = std::string(err);
            sqlite3_free(err);
        }
        return false;
    }
    return true;
}

#endif // SQLITEDB_H
