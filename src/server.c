#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#include "html.h"
#include <stdlib.h>
#include "index.c"
#include "about.c"
#include "errors.c"
#define PORT 8082
#define SOCKET_MAX_CONNS 128
#define BUFFER_SIZE 1024


int route(int fd, char* buffer) {
	printf("routing:\n");
	printf("%s", buffer);
        int i = 0;
        char *method, *path;

        method = strtok(buffer, " ");
        path = strtok(NULL, " ");

        printf("method: %s\n", method);
        printf("path: %s\n", path);

        if (strcmp(method,"GET") != 0)
        {
            return write(fd, get_method_not_allowed(), strlen(get_method_not_allowed()));
        }

        if (strcmp(path, "/") == 0)
        {
            return write(fd, get_index_html(), strlen(get_index_html()));
        }

        if (strcmp(path, "/about") == 0)
        {
            return write(fd, get_about_html(), strlen(get_about_html()));
        }

        return -1;
}


int main() 
{
    char buffer[BUFFER_SIZE];
    int socket_fd = -1;
    int client_fd = -1;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        return 1;
    }
    printf("socket created successfully\n");

    struct sockaddr_in host_addr;
    int hostaddr_len = sizeof(host_addr);

    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(PORT);
    host_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(socket_fd, (struct sockaddr *)&host_addr, hostaddr_len) != 0)
    {
        perror("bind");
        close(socket_fd);
        return 1;
    }

    printf("socket bound to address\n");

    if (listen(socket_fd, SOCKET_MAX_CONNS) != 0)
    {
        perror("listen");
        close(socket_fd);
        return 1;
    }

    printf("server listening for connections\n");

    while (1)
    {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        client_fd = accept(socket_fd, 
                          (struct sockaddr *)&client_addr, 
                          (socklen_t *)&client_addr_len);
        if (client_fd < 0) 
        {
            perror("accept");
            continue;
        }
        printf("connection accepted\n");

        ssize_t bytes_read = read(client_fd, buffer, BUFFER_SIZE - 1);
        if (bytes_read < 0) 
        {
            perror("read");
            close(client_fd);
            continue;
        }
        if (bytes_read > 0)
        {
            buffer[bytes_read] = '\0';
        }

        ssize_t output = route(client_fd, buffer);
        if (output < 0)
        {
            perror("write");
            close(client_fd);
            continue;
        }

        close(client_fd);
        client_fd = -1;
    }

    if (client_fd != -1) {
        close(client_fd);
    }
    if (socket_fd != -1) {
        close(socket_fd);
    }

    return 0;
}
