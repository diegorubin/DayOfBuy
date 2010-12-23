#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>
#include <iostream>
#include <list>

#include "user.h"

#include "../shared/message.h"

using namespace std;

class Server {
public:
  Server(int port);
  virtual ~Server();

  //methods
  void start();

private:
  // attributes
  int i;
  int port;
  int server_socket;
  int total_clients;

  list<int> clients;

  struct sockaddr_in local;

  // methods
  void setup(); 
  int accept_connection();
  void execute_action(message received);
  
  // action methods
  void create_user(char m_content[content_len]);
};

// actions
#define CREATE_USER "aus"

#endif //_SERVER_H_

