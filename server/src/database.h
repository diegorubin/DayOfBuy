#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <sqlite3.h>
#include "config.h"

class Database {
public:
    Database();
    virtual ~Database();

protected:
    // attributes
    char *cError;
};

#endif // _DATABASE_H_
