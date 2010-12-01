#include "user.h"

User::User()
{
}

User::~User()
{
}

bool User::create()
{
  string sql = "INSERT INTO USERS(name, login, passwd) values (";
  sql.append("'" + name + "',");
  sql.append("'" + login + "',");
  sql.append("'" + passwd + "');");
  sqlite3_exec(db,sql.c_str(),create_callback,0,cError);
  return true;
}

// sets
void User::set_name(string value)
{
    name = value;
}

void User::set_login(string value)
{
    login = value;
}

void User::set_passwd(string value)
{
    passwd = value;
}

