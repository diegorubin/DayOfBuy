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
  db->execute(sql);
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

