#include <iostream>
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
    int port;

    // parse methods
    void default_config();

private:
    bool config_file_exists();
};

