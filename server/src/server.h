#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>
#include <iostream>

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

  struct sockaddr_in local;

  // methods
  void setup(); 
};

#endif //_SERVER_H_

