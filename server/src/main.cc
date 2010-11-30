#include "server.h"
#include "database.h"
#include "user.h"


int main(int argc, char *argv[])
{
    db = new Database();

    // teste

    User user;
    user.set_name("Diego Rubin");
    user.set_login("drubin");
    user.set_passwd("teste");
    user.create();

    Server server(7777);
    server.start();
    return 0;
}

