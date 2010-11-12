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
    if(listen(server_socket,number_of_clients) < 0){
        cout << "Erro na escuta do servidor.\n";
        exit(3);
    }

    while(true){
        struct pollfd pfds[1];
        pfds[0].fd = server_socket;
        pfds[0].events = POLLIN;

        poll(pfds,10,-1);
        
        //accept connection
        if(pfds[0].revents != 0) accept_connection();

    }
}

void Server::accept_connection()
{
    // retorna socket
    accept(server_socket,NULL,NULL);
    cout << "Conexão estabelecida com cliente.";
}

