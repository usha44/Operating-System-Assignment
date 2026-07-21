#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {

    int sock;
    struct sockaddr_in server;

    char username[50];
    char password[50];
    char message[100];
    char reply[100];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr *)&server, sizeof(server));

    printf("Username: ");
    scanf("%49s", username);

    printf("Password: ");
    scanf("%49s", password);

    sprintf(message, "%s %s", username, password);

    write(sock, message, strlen(message));

    read(sock, reply, sizeof(reply));

    printf("\nServer Response: %s\n", reply);

    close(sock);

    return 0;
}
