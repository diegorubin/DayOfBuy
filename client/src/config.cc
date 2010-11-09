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

    file << "[host]" << host << "\n";
    file << "[port]" << port << "\n";

    file.close();
    return true;
}

bool Config::load()
{
    char c;
    char attr[255],value[10000];
    int pos_attr = 0;
    int pos_value = 0;

    bool is_value = false;
    ifstream file;
    file.open(config_file.c_str(), std::ios::in);

    if(!file.is_open()) return false;

    while(file.get(c)){
        switch(c){
            case T_BEGIN_ATTR:{
                pos_attr = 0;
                break;
            }
            case T_END_ATTR:{
                pos_value = 0;
                is_value = true;
                break;
            }
            case T_END_VALUE:{
                is_value = false;
                set_value(attr,value);
                break;
            }
            default:{
                if(is_value) value[pos_value++] = c;
                else attr[pos_attr] = c;
            }
        }
    }

    return true;
}

void Config::set_value(string attr, string value)
{
    if(attr == "host") host = value;
}
