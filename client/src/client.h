#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <iostream>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>

#include "../shared/message.h"

using namespace std;

class Client{
public:
    Client();
    virtual ~Client();

    // methods
    bool server_connect(const char *host, int port);
    bool create_new_user(string name, string login, string passwd);

private:
    // attributes
    int client_socket;
    struct sockaddr_in server;
};

#endif //_CLIENT_H_
