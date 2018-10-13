#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main( int argc, char **argv) {
    /*
    if (argc != 3) {
      printf("Usage: %s [host] [port]\n", argv[0]);
      exit(1);
    }
    */

    // create a socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // specifying address
    struct sockaddr_in  server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9001);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    /* To connect */
    int conn_stat = connect(network_socket, (struct sockaddr * ) &server_addr, sizeof(server_addr));
    if (conn_stat == -1) {
        printf("Can't connect to the ip and port %d\n", 9001);
        exit(1);
    }

    // reading response of the server
    char resp[256];
    recv(network_socket, resp, sizeof(resp), 0);

    // printing the data which is recieved
    printf("%s\n", resp);

    // closing the socket
    close(socket);

    return 0;
}
