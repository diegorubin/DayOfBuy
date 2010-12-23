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
                    execute_action(*received);
                }
            }
        }
    }
}

int Server::accept_connection()
{
    return accept(server_socket,NULL,NULL);
}

void Server::execute_action(message received)
{
    cout << "Executando ação: " << received.action << endl;
    int result = strcmp(received.action,"aus");
    if(result == 0) create_user(received.content);
}

void Server::create_user(char m_content[content_len])
{
    cout << "Criando novo usuário" << endl;
    int i_field = 0;
    int pos = 0;
    char c_field[content_len];
    char c[2];
    User user;

    c[0] = '0';
    while(c[0] != '\0'){
        c[0] = m_content[pos++];
        if(c[0] == '|'){
            i_field++;
            switch(i_field){
                case 1:{
                    printf("name: %s",c_field);
                    user.set_name(c_field);
                    break;
                }
                case 2:{
                    printf("login: %s",c_field);
                    user.set_login(c_field);
                    break;
                }
                case 3:{
                    printf("passwd: %s",c_field);
                    user.set_passwd(c_field);
                    break;
                }
            }
            c_field[0] = '\0';
        }
        else{
            strcat(c_field,c);
        }
    }

}
