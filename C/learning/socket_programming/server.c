#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main( int argc, char **argv) {
    /*
    if (argc < 2) {
        fprintf(stderr, "Port number not provided!\n");
        exit(1);
    }
    */

    // Message to send to the client
    char server_message[256] = "Hello Client";

    // creating the network socket
    int network_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (network_socket == -1) {
        printf("couldn't make the socket\n");
    }

    // structure 'sockaddr_in' holds the nessesary data
    // to ip and port number and family
    struct sockaddr_in ser_addr;
    ser_addr.sin_family = AF_INET;

    // port number
    // htons is used to change the format to little endian to big endian format
    // big endian format is used for network data transfer
    ser_addr.sin_port = htons(9001);
    ser_addr.sin_addr.s_addr = INADDR_ANY;

    // Binding the socket to the 0.0.0.0 ip and setting the port
    bind(network_socket, (struct sockaddr *) &ser_addr, sizeof(ser_addr));

    // Now we can listen for client to connect
    // same as we were waiting for a caller to call to our phone
    listen(network_socket, 5);     // 5 is the number of clients it can handle

    // when client connects we get a client socket
    int client_socket;
    client_socket = accept(network_socket, NULL, NULL);   // this accept function accepts the client

    // sending the server_message to client
    send(client_socket, server_message, sizeof(server_message), 0);

    // closing the connection
    close(network_socket);

    return 0;
}
