#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>
#include <iostream>

class Server {
public:
  Server(int port);
  virtual ~Server();

private:
  // attributes
  int i;
  int port;
  int socket;

  struct sockaddr_in local = { AF_INET };

  // methods
  int setup(); 
};
