#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define PORT 8080
#define SOCKET_MAX_CONNS 128
#define BUFFER_SIZE 1024


int main() 
{
	char buffer[BUFFER_SIZE];

	char response[] = "HTTP/1.1 200 OK\r\n"
		          "Content-Length: 85\r\n"
		          "Content-type: text/html\r\n\r\n"
		          "<html><body>"
			  "This is <strong>hyperprior</strong>, we'll be back soon"
		          "</body></html>\r\n";

	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
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
		return 1;
	}

	printf("socket bound to address\n");

	if (listen(socket_fd, SOCKET_MAX_CONNS) != 0)
	{
		perror("listen");
		return 1;
	}

	printf("server listening for connections\n");

	while (1)
	{
		struct sockaddr_in client_addr;;
		socklen_t client_addr_len = sizeof(client_addr);
		int client_fd = accept(socket_fd, 
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
			printf("received %s\n", buffer);
		}

		ssize_t output = write(client_fd, response, strlen(response));
		if (output < 0)
		{
			perror("write");
			close(client_fd);
			continue;
		}


		close(client_fd);
	}

	return 0;
}
