#include "server.h"

Server::Server(int port)
{
    // yes, this is a magic number
    total_clients = 40;
    
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

    list<int>::iterator it;

    if(listen(server_socket,total_clients) < 0){
        cout << "Erro na escuta do servidor.\n";
        exit(3);
    }
    else{
        cout << "Servidor startado." << endl;
    }
    
    struct pollfd pfds[total_clients];
    pfds[0].fd = server_socket;
    pfds[0].events = POLLIN;

    while(true){
        poll(pfds, clients.size()+1, -1);
        //accept new connection
        if(pfds[0].revents != 0){ 
          int new_connection = accept_connection();
          clients.push_back(new_connection);
          pfds[clients.size()].fd = new_connection;
          pfds[clients.size()].events = POLLIN;
        }

        for(it=clients.begin(); it != clients.end(); it++){
            int position = distance(clients.begin(),it) +1;
            if(pfds[position].revents !=0){
                char buffer[2000];
                int r = recv(*it,buffer,sizeof(buffer),0);
                if(r > 0){
                    message *received = (message*) &buffer;
                    cout << "Mensagem recebida de cliente" << endl;
                    cout << "Ação requerida: " << received->action << endl;
                }
            }
        }
    }
}

int Server::accept_connection()
{
    return accept(server_socket,NULL,NULL);
}

