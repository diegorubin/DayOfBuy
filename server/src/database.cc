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

