#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <iostream>
#include <sqlite3.h>
#include "config.h"

using namespace std;

class Database {
public:
    Database();
    virtual ~Database();

    // methods
    bool execute(string sql);
    char** error_msg();

private:
    // attributes
    sqlite3 *db;
    char **cError;
};
static Database *db;

#endif // _DATABASE_H_
