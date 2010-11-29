#include "server.h"
#include "database.h"

int main(int argc, char *argv[])
{
    Database db;
    Server server(7777);
    server.start();
    return 0;
}

