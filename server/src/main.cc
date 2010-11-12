#include "server.h"

int main(int argc, char *argv[])
{
    Server server(7777);
    server.start();
    return 0;
}

