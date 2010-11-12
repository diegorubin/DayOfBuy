#include "server.h"

Server::Server(int port)
{
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
    if(listen(server_socket,10) < 0){
        cout << "Erro na escuta do servidor.\n";
        exit(3);
    }
}

