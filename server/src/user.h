#ifndef _USER_H_
#define _USER_H_

#include <iostream>

using namespace std;

class User {
public:
    User();
    virtual ~User();

private:
    // attributes
    string name;
    string login;
    string passwd;
};

#endif //_USER_H_
