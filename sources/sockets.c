#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int socket_create() {
    int h_socket;
    printf("Create the socket\n");
    h_socket = socket(AF_INET, SOCK_STREAM, 0);
    return h_socket;
}

int bind_create_socket(int h_socket) {
    int i_ret_val = -1;
    int client_port = 8080;

    struct sockaddr_in remote = {0};

    // internet address family
    remote.sin_family = AF_INET;

    // any incoming interface
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(client_port);

    i_ret_val = bind(h_socket, (struct sockaddr *) &remote, sizeof(remote));
    return i_ret_val;
}

int create_server() {
    int socket_desc = 0, sock = 0, client_len = 0;
    struct sockaddr_in client;
    char client_message[200] = {0};
    char message[100] = {0};
    const char *pMessage = "Hello from server";

    // create socket
    socket_desc = socket_create();
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    printf("Socket created\n");

    // bind
    if (bind_create_socket(socket_desc) < 0) {
        perror("bind failed.");
        return 1;
    }

    printf("Bind done");

    // listen
    listen(socket_desc, 3);

    while (1) {
        printf("Waiting for incoming connections...\n");
        client_len = sizeof(struct sockaddr_in);

        // accept connection from an incoming client
        sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t *) &client_len);

        if (sock < 0) {
            perror("accept failed");
            return 1;
        }

        printf("Connection accepted\n");
        memset(client_message, '\0', sizeof(client_message));
        memset(message, '\0', sizeof(message));

        // receive a reply from the client
        if (recv(sock, client_message, 200, 0) < 0) {
            printf("recv failed");
            break;
        }

        printf("Client reply: %s\n", client_message);

        if (strcmp(pMessage, client_message) == 0) {
            strcpy(message, "Hi there!");
        } else {
            strcpy(message, "Invalid Message!");
        }

        // send some data
        if (send(sock, message, strlen(message), 0) < 0) {
            printf("Send failed");
            return 1;
        }

        close(sock);
        sleep(1);
    }
    return 0;
}

int socket_connect(int h_socket) {
    int iRetVal = -1;
    int server_port = 8080;

    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote.sin_family = AF_INET;
    remote.sin_port = htons(server_port);

    iRetVal = connect(h_socket, (struct sockaddr *) &remote, sizeof(remote));
    return iRetVal;
}

int socket_send(int h_socket, char *request, int len_request) {
    int shortRetVal = -1;
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;

    if (setsockopt(h_socket, SOL_SOCKET, SO_SNDTIMEO, (char *) &tv, sizeof(tv))){
        printf("Time Out\n");
        return -1;
    }

    shortRetVal = send(h_socket, request, len_request, 0);
    return shortRetVal;
}

int sockets() {
    int h_socket = 0,read_size= 0;
    struct sockaddr_in server;
    char send_to_server[100] = {0};
    char server_reply[200] = {0};

    // create socket
    h_socket = socket_create();

    if (h_socket == -1){
        printf("Could not create socket\n");
        return 1;
    }

    printf("Socket is created\n");

    // connect to remote server
    if (socket_connect(h_socket)<0){
        perror("connect failed.\n");
        return 1;
    }

    printf("Successfully connected with server\n");
    printf("Enter the message: \n");
    fgets(send_to_server, 100, stdin);

    // send data to the server
    socket_send(h_socket, send_to_server, strlen(send_to_server));

    // received the data from the server


    return 0;
}