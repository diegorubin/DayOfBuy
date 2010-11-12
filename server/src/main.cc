#include "server.h"

int main(int argc, char *argv[])
{
	/*
	for (;;) {

		struct pollfd pfds[10];
	

		pfds[0].fd = socket;
		pfds[0].events = POLLIN;
		
		poll(pfds, 10, -1);

	    //nova conexao
		if (pfds[0].revents != 0) {
		    printf("nova conexao de client.\n");
		    clients[last_client] = accept(socket,NULL,NULL);
		    		    
		    pfds[last_client+1].fd = clients[last_client];
		    pfds[last_client+1].events = POLLIN;
		    
		    last_client++;
		}
		
		//recebendo do cliente
		for(i = 1; i <= 10; i++){
		    if (pfds[i].revents != 0) {
		        char buffer[8192];
		        
		        int r = recv(clients[i-1],buffer, sizeof(buffer),0);
		        if(r > 0){
		           message_t *received = (message_t*) &buffer ;
		           printf("recebido informacao de client.\n");
		           send_others(i-1, *received);
		         }
		    }
		}
		
	}

  */
  return 0;
}

