/*
Compilation: gcc -o client client.c
Execution  : ./client 5000

Requirements:
Client
Clients runs on any cse machine 02-6
Send a complete sentence to server
Receive message from server with number of vowels and print
Send "bye" message to server to close connection with server

*/

//These are pretty much standard for C socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <error.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])  //command line arguments
{
	int sockfd, portno, n;    //variable declarations
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[256];

	if (argc < 2)  //check number of CLAs
	{
		printf("\nPort number is missing...\n");
		exit(0);
	}

	portno = atoi(argv[1]);  //taking the second argument as the port number
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error(EXIT_FAILURE, 0, "ERROR opening socket");
	server = gethostbyname("129.120.151.94"); //IP address of server on cse01

	if (server == NULL)  // if no server is found to connect to
	{
		printf("\nERROR, no such host...\n");
		exit(0);
	}

	//Connecting with the server
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(portno);
	memcpy(&serv_addr.sin_addr, server->h_addr, server->h_length);
	if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
		error(EXIT_FAILURE, 0, "ERROR connecting the server...");

	while (1)  //continually run
	{
		//Sending the message to the server
		printf("\nEnter client's message: ");
		bzero(buffer,256);
		gets(buffer);
		n = write(sockfd, buffer, strlen(buffer));

		if (n < 0)
		{
			error(EXIT_FAILURE, 0, "ERROR writing to socket");
		}
		 else if ((strcmp(buffer, "bye") == 0 || strcmp(buffer, "Bye") == 0)) //server will sever connection but and the client will shut down if 'bye' is sent
                {
                       break;  //if the buffer is 'bye' break and close client
                }


		//Receiving the message from the server
		bzero(buffer,256);
		n = read(sockfd, buffer, 255);
		if (n < 0)
			error(EXIT_FAILURE, 0, "ERROR reading from socket");
		else
		{
			printf("Number of vowels is %s\n", buffer);  //print off the number of vowels
		}
	}

return 0;
}
