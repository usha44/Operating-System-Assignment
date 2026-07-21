#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server, client;
    socklen_t len = sizeof(client);

    char buffer[100];
    char username[50], password[50];
    char dbuser[50], dbpass[50];
    int found = 0;

    FILE *fp;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr *)&server, sizeof(server));
    listen(server_fd, 5);

    printf("Server waiting for client...\n");

    client_fd = accept(server_fd, (struct sockaddr *)&client, &len);

    read(client_fd, buffer, sizeof(buffer));

    sscanf(buffer, "%s %s", username, password);

    printf("Username: %s\n", username);
    printf("Password: %s\n", password);

    fp = fopen("users.db", "r");

    while (fscanf(fp, "%s %s", dbuser, dbpass) != EOF) {
        if (strcmp(username, dbuser) == 0 &&
            strcmp(password, dbpass) == 0) {
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found)
        write(client_fd, "SUCCESS", 7);
    else
        write(client_fd, "FAILED", 6);

    close(client_fd);
    close(server_fd);

    return 0;
}




