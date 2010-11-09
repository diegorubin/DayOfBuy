#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <iostream>
#include <fstream>
#include <stdlib.h>

enum tokens {
    T_BEGIN_ATTR = '[',
    T_END_ATTR = ']',
    T_END_VALUE = '\n'
};

using namespace std;

class Config
{
public:
    Config();
    Config(string config_file);
    virtual ~Config();

    string config_file;

    // preferences attributes
    string host;
    string port;

    // parse methods
    bool save();
    bool load();

private:
    void set_value(string attr, string value);
    bool config_file_exists();
};

#endif //_CONFIG_H_

