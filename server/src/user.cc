#include "user.h"

User::User()
{
    cError = 0;
}

User::~User()
{
}

bool User::create()
{
    int rc;

    char sql[500];
    sprintf(sql, "INSERT INTO USERS(name, login, passwd) VALUES ('%s','%s','%s');",name,login,passwd);
    rc = sqlite3_exec(db,sql,NULL,NULL,&cError);
    if(rc != SQLITE_OK){
        fprintf(stderr,"Sqlite3: %s\n",cError);
        return false;
    }
    else{
        printf("Criando novo usuário.\n");
        return true;
    }
}

// sets
void User::set_name(const char *value)
{
    name = value;
}

void User::set_login(const char *value)
{
    login = value;
}

void User::set_passwd(const char *value)
{
    passwd = value;
}

