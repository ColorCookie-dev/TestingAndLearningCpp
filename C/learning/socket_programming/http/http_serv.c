#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Usage: %s [port no.]\n", argv[0]);
        exit(1);
    }

    FILE *html_data;
    html_data = fopen("index.html", "r");

    // Getting the content of the file 'response_data' holds the data
    char response_data[40960];   // if you change the size here, also change the value in line no 15
    // This is the header of the html contains version and the status 200
    // here 200 means
    char http_header[40980] = "HTTP/1.1 200 OK\r\n\n";
    // fgets reads the data from the file that 'html_data' holds
    char line[40960];
    while (fgets(line, 40960, html_data)) {
        strncat(response_data, line, sizeof(line));
    }
    // merges the two strings
    strncat(http_header, response_data, sizeof(response_data));
    // closing the FILE
    fclose(html_data);

    // creating a socket
    int network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // defining the address and the family
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    // atoi converts string into int
    serv_addr.sin_port = htons(atoi(argv[1]));  // port converting to the big endian format
    printf("%d\n", ntohs(serv_addr.sin_port));
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Binding to the client_socket
    // this takes some parameters
    // 1. socket 2. server address 3. size of server address structure
    int check_bind = bind(network_socket, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (check_bind == -1) {
        printf("[-] Couldn't bind to the give address: %s and port %d\n", serv_addr.sin_addr.s_addr, serv_addr.sin_port);
        exit (1);
    }
    // listening on the socket
    listen(network_socket, 5);

    // expecting clients
    int client_socket;
    // to always listen for clients
    while (1) {
        client_socket = accept(network_socket, NULL, NULL);  // These nulls doesn't matter for Now
        // sending clients the file
        send(client_socket, http_header, sizeof(http_header), 0);   // sending packets
        // now we don't have any work with the clients
        close(client_socket);
    }

    return 0;
}
