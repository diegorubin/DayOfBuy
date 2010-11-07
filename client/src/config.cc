#include "config.h"

Config::Config()
{
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

void Config::default_config()
{
    
}

bool Config::config_file_exists()
{
}

