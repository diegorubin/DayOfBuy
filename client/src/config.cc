#include "config.h"

Config::Config()
{
    host = "127.0.0.1";
    port = "7777";

    config_file = getenv("HOME");
    config_file.append("/.dobrc");
}

Config::Config(string config_file)
{
    this->config_file = config_file;
}

Config::~Config()
{
}

bool Config::config_file_exists()
{
}

bool Config::save()
{
    ofstream file;
    file.open(config_file.c_str(), std::ios::out);

    if(!file.is_open()) return false;

    file << "[host]:" << host << "\n";
    file << "[port]:" << port << "\n";

    file.close();
    return true;
}

