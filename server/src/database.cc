#include "database.h"

Database::Database()
{
    int result = sqlite3_open(DB_DIR, &db);
    if (result) {
        cerr << "Não foi possível abrir o banco de dados. Erro: " << sqlite3_errmsg(db);
        sqlite3_close(db);
    }
}

Database::~Database()
{
    sqlite3_close(db);
}

bool Database::execute(string sql)
{
    sqlite3_exec(db,sql.c_str(),NULL,NULL,cError);
    return true;
}

char** Database::error_msg()
{
    char **erro;
    erro = cError;
    cError = NULL;
    return cError;
}

