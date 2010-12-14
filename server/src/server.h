#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>
#include <iostream>
#include <list>

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
};

#endif //_SERVER_H_

