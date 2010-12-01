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

    // callbacks
    static int create_callback(void *NotUsed, int argc, char **argv, char **azColName);

protected:
    // attributes
    char **cError;
};
static sqlite3 *db;

#endif // _DATABASE_H_
