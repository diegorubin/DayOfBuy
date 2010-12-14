#include "client.h"

Client::Client()
{
}

Client::~Client()
{
}

bool Client::server_connect(const char *host, int port)
{
	server = { AF_INET };

	if (inet_pton(AF_INET, host, &server.sin_addr) <= 0){
		cout << "Falha ao tentar conectar ao servidor.\n";
		return false;
    }

	server.sin_port = htons(port);

	client_socket = socket(PF_INET, SOCK_STREAM, 0);
	if(client_socket < 0 ){
		cout << "Falha ao criar conexão com o servidor.\n";
		return false;
    }

	if (connect(client_socket,(struct sockaddr*) &server, sizeof(server)) < 0){
		cout << "Erro ao conectar com o servidor.\n";
		return false;
    }

	return true;
}

bool Client::create_new_user(string name, string login, string passwd)
{
    message new_user;
    sprintf(new_user.action,"aus");
    sprintf(new_user.content,"%s|%s|%s",name.c_str(),login.c_str(),passwd.c_str());

    if(connected){
        if(send(client_socket, (char *)&new_user, sizeof(message), 0))
            return true;
    }

    return false;
}

