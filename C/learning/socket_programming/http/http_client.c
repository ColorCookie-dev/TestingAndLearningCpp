#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
// new include header file
// contains functions to convert host ip address charset to useable type just like with the Port
// htons was used
#include <arpa/inet.h>

int main(int argc, char **argv) {

    // checking if the required arguments are given
    if (argc != 3) {
        printf("Usage: %s [host] [port]\n", argv[0]);
        exit(1);
    }

    // storing the host ip and port value to connect
    char *address = argv[1];         // this is the host ip
    int port = atoi(argv[2]);        // this is the port of the host ip

    // to store host address to connect later
    struct sockaddr_in host_addr;           // making the struct which will be the input in the function connect
    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(port);           // Setting the port in big endian format
    // setting the ip address in a format that the network socket can understand to connect to the ip
    inet_aton(address, &host_addr.sin_addr.s_addr);   // this function takes the values to convert and also where to store
                                                      // the value post conversion but it needs to the address of the variable
                                                      // to store
    // creating a socket for the client
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    // connecting to the host server
    connect(client_socket, (struct sockaddr *) &host_addr, sizeof(host_addr));

    // prepairing the request
    // https = {method} / HTTP/{version}\r\n\r\n
    char request[] = "GET / HTTP/1.1\r\n\r\n";
    char response[4096];
    // sending the request this takes socket, string , size of the string, and another unnecessary thing as parameters
    send(client_socket, request, sizeof(request), 0);
    while (recv(client_socket, &response, sizeof(response), 0)) {
        // recieving the response, nearly same as send function
        // printing the resource
        printf("%s", response);
        strcpy(response, "");
    }

    // closing the connection
    close(client_socket);

    return 0;
}
