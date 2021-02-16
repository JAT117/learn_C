
/*
Compilation: gcc -o server server.c
Execution  : ./server 5000

Requirements:
Server runs on the cse01 machine
Return number of vowels to the server
When receiving "Bye" or "bye", disconnect from client
*/

#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <error.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])  //command line arguments
{
	int sockfd, newsockfd, portno, clilen, n;  //variable declaration
	struct sockaddr_in serv_addr, cli_addr;
	char buffer[256];

	if (argc < 2)    //checking the number of command line arguments
	{
		printf("\nPort number is missing...\n");
		exit(0);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error(EXIT_FAILURE, 0, "ERROR opening socket");
	bzero((char *)&serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);                                   //user defined port number
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		error(EXIT_FAILURE, 0, "ERROR binding");

	printf("\nServer Started and listening to the port %d\n", portno);  //success


	while (1)  // running
	{
		listen(sockfd, 5); //Connecting with the client
		clilen = sizeof(cli_addr);
		fork();      //forks the process for different client instances

		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		if (newsockfd < 0)
			error(EXIT_FAILURE, 0, "ERROR on accept");
		printf("\nClient is connected...\n");

		//Receiving the message from the client

		while (1)  //forever
		{
			int vowels = 0;
			bzero(buffer, 256);
			n = read(newsockfd, buffer, 255);

			if (n < 0)
			{
				error(EXIT_FAILURE, 0, "ERROR reading from socket");
			}
			else if ((strcmp(buffer, "bye") == 0 || strcmp(buffer, "Bye") == 0))  //Start of meat
			{
				close(newsockfd);       //Closing the connection
				break;
			}
			else
			{

				printf("\nClient has sent: %s\n", buffer);
				int i;
				for (i = 0; buffer[i] != '\0'; ++i)   //count up the vowels
				{
					if (buffer[i] == 'a' || buffer[i] == 'A')
					{
						++vowels;
					}
					if (buffer[i] == 'e' || buffer[i] == 'E')
					{
						++vowels;
					}
					if (buffer[i] == 'i' || buffer[i] == 'I')
					{
						++vowels;
					}
					if (buffer[i] == 'o' || buffer[i] == 'O')
					{
						++vowels;
					}
					if (buffer[i] == 'u' || buffer[i] == 'U')
					{
						++vowels;
					}
				}
				//Sending the message to the client
				bzero(buffer, 256);
				sprintf(buffer, "%d", vowels);  //converts int vowels to string for buffer
				printf("%s", buffer);		//end of meat
				n = write(newsockfd, buffer, strlen(buffer));  //send buffer to client

			}
		}
	}

return 0;
}
