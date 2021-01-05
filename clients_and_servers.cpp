
//server
int sockfd = socket(domain, type, protocol);
int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int listen(int sockfd, int backlog);
int new_socket = accept(int sockfd, const sockaddr *addr, socklen_t addrlen);

//client 
int connect(int sockfd, const sockaddr *addr, socklen_t addrlen);

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	char *hello = "Hello from server";
	
	//Create socket file descriptor
	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) //return 0 if fails  
	{
		perror("Socket Failed");
		exit(EXIT_FAILURE);
	}
	
	//forcefully attach socket to PORT
	if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	
	//bind file descriptor
	if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
	if(listen(server_id, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	
	if(new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen) < 0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
	
	valread = read(new_socket, buffer, 1024);
	printf("%s\n", buffer);
	send(new_socket, hello, strlen(hello), 0);
	printf("Hello message sent\n");
	return 0;
}

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
	int sock = 0, valread;
	struct sockaddr_in server_address;
	char buffer[1024] = {0};
	char *hello = "Hello from client";
	
	//Create socket file descriptor
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) //return 0 if fails  
	{
		perror("socket creation failed");
		return -1;
	}
	
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);
	
	//Convert IPv4 and IPv6 from text to binary form
	if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0)
	{
		perror("\nInvalid address");
		return -1;
	}
	
	if(connect(sock, (struct sockaddr *)&server_address, sizeoff(server_address)) < 0)
	{
		perror("connection failed");
		return -1;
	}
	
	send(sock, hello, strlen(hello), 0);
	printf("Hello message sent\n");
	valread = read(sock, buffer, 1024);
	printf("%s\n", buffer);
	return 0;
}
