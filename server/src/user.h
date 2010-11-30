#ifndef _USER_H_
#define _USER_H_

#include <iostream>
#include "database.h"

extern Database *db;

using namespace std;

class User {
public:
    User();
    virtual ~User();

    //methods
    bool create();

    //sets
    void set_name(string value);
    void set_login(string value);
    void set_passwd(string value);
private:
    // attributes
    string name;
    string login;
    string passwd;
};

#endif //_USER_H_
