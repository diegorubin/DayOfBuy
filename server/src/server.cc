#include "server.h"

Server::Server(int port)
{
  this->port = port;

  local.sin_addr.s_addr= htonl(INADDR_ANY);
  local.sin_port = htons(this->port);
}

Server::~Server()
{
}

int Server::setup()
{
    int clientsock;
    
    struct sockaddr_in server = { AF_INET };
    
    if (inet_pton(AF_INET, host, &server.sin_addr) <= 0)
    	fatal("Falhou ao interpretar o endereço IP.");
    
    server.sin_port = htons(port);
    
    clientsock = socket(PF_INET, SOCK_STREAM, 0);
    if(clientsock < 0 )
    	fatal("Erro na criação do socket cliente.");
    
    if (connect(clientsock,(struct sockaddr*) &server, sizeof(server)) < 0)
    	fatal("Erro ao conectar com o servidor");
    
    printf("*** Conexão estabelecida.\n");
    return clientsock;
}

