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

private:
    sqlite3 *db;
};

#endif // _DATABASE_H_
