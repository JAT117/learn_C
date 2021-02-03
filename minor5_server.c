/*
jat0307	
server
sends and receives files
*/

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#define port 5001  //port number
#define BUFFER 1024 //buffer size

int main() 
{
	int  n, i, soc, nsoc, cli, active = 1;
	char ch, buffer[BUFFER]; // create buffer
	struct sockaddr_in serv_addr, cli_addr;


	/* First call to socket() function */
	soc = socket(AF_INET, SOCK_STREAM, 0);

	if (soc < 0) {
		perror("ERROR opening socket");
		exit(1);
	}

	/* Initialize socket structure */
	bzero((char *) &serv_addr, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port);

	/* Now bind the host address using bind() call.*/
	/* if (bind(soc, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
	{
		fprintf(stderr, "ERROR (errno = %d)\n",errno);
		exit(1);
	}
 */
	/* Now start listening for the clients, here process will
      * go in sleep mode and will wait for the incoming connection
	*/

	listen(soc,5);
	cli = sizeof(cli_addr);

	/* Accept actual connection from the client */
	nsoc = accept(soc, (struct sockaddr *)&cli_addr, &cli);

	if (nsoc < 0) 
	{
		perror("ERROR on accept\n");
		exit(1);
	}
	while (active == 1) //loop until quit is received
	{
		/* If connection is established then start communicating */
		printf("waiting for command:\n");
		bzero(buffer,BUFFER); //clear buffer
		n = read(nsoc,buffer,BUFFER); //read into buffer

		if (n < 0) 
		{
			fprintf(stderr, "ERROR (errno = %d)\n",errno);
			exit(1);
		}
		if(strcmp(buffer, "put") == 0) //if "put" received
		{
			printf("receiving file\n"); //prepare to receive file
			bzero(buffer,BUFFER);
			n = read(nsoc,buffer, BUFFER); //read filename
			if (n < 0) 
			{
				fprintf(stderr, "ERROR (errno = %d)\n",errno);
				exit(1);
			}
			printf("The file name is %s\n", buffer); //print filename
			
			if(access(buffer, F_OK) != -1) //check if file exists
			{
				printf("error file already exists\n");
				n = write(nsoc,"file already exists",20);
				if (n < 0) 
				{
					perror("ERROR writing to socket");
					exit(1);
				}
			}
			else 
			{
				FILE *file; 						//file 
				file = fopen(buffer, "w"); 			//create file
				bzero(buffer,BUFFER);
				n = read(nsoc,buffer,BUFFER);		//read contents
				for(i=0; i<strlen(buffer)-1; i++) 	//write into file
				{
					fprintf(stderr, "ERROR (errno = %d)\n",errno);						
				}
					
				fprintf(stderr, "ERROR (errno = %d)\n",errno);
				fclose(file); 				
				printf("write complete\n"); //ack
				n = write(nsoc,"SUCCESS!",17);
				if (n < 0) 
				{
					perror("ERROR writing to socket\n");
					exit(1);
				}
			}
		}
		else if(strcmp(buffer, "get") == 0)
		{
			printf("sending>>>n"); 
			bzero(buffer,BUFFER);
			n = read(nsoc,buffer, BUFFER); //file name
			if (n < 0) 
			{
				perror("ERROR reading from socket\n");
				exit(1);
			}
			printf("The file name is %s\n", buffer);
			if(access(buffer, F_OK) == -1) //does file exist?
			{
				n = write(nsoc,"file does not exist",20);
				if (n < 0) 
				{
					perror("ERROR writing to socket\n");
					exit(1);
				}
			}
			else 
			{
				FILE *file; 			//file
				file = fopen(buffer, "r"); //open file
				i = 0;
				bzero(buffer,512);
				while (ch != EOF) // while not end of file 
				{		
					ch = fgetc(file);
					buffer[i] = ch;
					i++;
					if(i==1023) 
					{
						printf("overflow\n");
						exit(1);
					}
				}
				buffer[i-1] = '\0'; //replace EOF with null terminator
				n = write(nsoc, buffer, strlen(buffer)); //send file contents to client
				if (n < 0) 
				{
					perror("ERROR writing to socket\n");
					exit(1);
				}
			}
		}
		else if(strcmp(buffer, "quit") == 0) //quit program
		{
			n = close(nsoc);
			active = 0;
		}
		else
			printf("error %s\n", buffer);

	}
	return 0;
}
