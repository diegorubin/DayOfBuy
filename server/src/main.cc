#include "server.h"
#include "database.h"
#include "user.h"

sqlite3 *db;

int main(int argc, char *argv[])
{

    // connect to database
    int result = sqlite3_open(DB_DIR, &db);
    if (result) {
        cerr << "Não foi possível abrir o banco de dados. Erro: " << sqlite3_errmsg(db);
        exit(1);
    }

    Server server(7777);
    cout << "Startando servidor" << endl;
    server.start();

    sqlite3_close(db);
    return 0;
}

