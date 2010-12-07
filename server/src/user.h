#ifndef _USER_H_
#define _USER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../shared/message.h"
#include "database.h"

extern sqlite3 *db;

class User : public Database {
public:
    User();
    virtual ~User();

    //methods
    bool create();

    //sets
    void set_name(const char *value);
    void set_login(const char *value);
    void set_passwd(const char *value);
    
private:
    // attributes
    const char *name;
    const char *login;
    const char *passwd;
};

#endif //_USER_H_
