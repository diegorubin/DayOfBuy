#include "server.h"
#include "database.h"
#include "user.h"


int main(int argc, char *argv[])
{

    //connect to database
    int result = sqlite3_open(DB_DIR, &db);
    if (result) {
        cerr << "Não foi possível abrir o banco de dados. Erro: " << sqlite3_errmsg(db);
        exit(1);
    }

    User user;
    user.set_name("Diego Rubin");
    user.set_login("drubin");
    user.set_passwd("teste");
    user.create();

    Server server(7777);
    server.start();
    sqlite3_close(db);
    return 0;
}

