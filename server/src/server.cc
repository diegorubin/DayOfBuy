#include "server.h"

Server::Server(int port)
{
    // yes, this is a magic number
    total_clients = 40;
    connected_clients = 0;

    this->port = port;

    local = {AF_INET};
    local.sin_addr.s_addr= htonl(INADDR_ANY);
    local.sin_port = htons(this->port);

    setup();
}

Server::~Server()
{
}

void Server::setup()
{
    server_socket = socket(PF_INET, SOCK_STREAM, 0);
	if(server_socket < 0 ){
		cout << "Erro ao criar socket do servidor.\n";
		exit(1);
    }
		
	if (bind(server_socket,(struct sockaddr*) &local, sizeof(local)) < 0){
		cout << "Erro na criação da porta.\n";
		exit(2);
    }
	
}

void Server::start()
{
    if(listen(server_socket,total_clients) < 0){
        cout << "Erro na escuta do servidor.\n";
        exit(3);
    }
    
    struct pollfd pfds[total_clients];
    pfds[0].fd = server_socket;
    pfds[0].events = POLLIN;

    while(true){
        poll(pfds, connected_clients+1, -1);
        //accept new connection
        if(pfds[0].revents != 0){ 
          clients[connected_clients-1] = accept_connection();
          pfds[connected_clients].fd = clients[connected_clients-1];
          pfds[connected_clients].events = POLLIN;
        }
    }
}

int Server::accept_connection()
{
    connected_clients++;
    return accept(server_socket,NULL,NULL);
}

