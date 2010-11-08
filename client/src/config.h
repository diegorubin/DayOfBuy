#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <iostream>
#include <fstream>
#include <stdlib.h>

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

private:
    bool config_file_exists();
};

#endif //_CONFIG_H_

