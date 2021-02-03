/*
jat0307	
server
sends and receives files
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#define port 5001  //port number
#define BUFFER 1024 //buffer size

int main(int argc, char *argv[]) 
{
	int soc, n, i;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[512];
	char file_name[512];
	char ch, *str;

	server = gethostbyname("cse06.cse.unt.edu"); //hardcoded server
	soc = socket(AF_INET, SOCK_STREAM, 0);

	if (soc < 0) 
	{
		perror("ERROR opening socket");
		exit(1);
	}

	if (server == NULL) 
	{
		fprintf(stderr,"ERROR, no such host\n");
		exit(0);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(port);


	if (connect(soc, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
	{
		perror("ERROR connecting");
		exit(1);
	}

	while(1) //loop until quit command is given
	{
		printf("Connection Established: "); //signal that connection was successful
		bzero(buffer,512);
		fgets(buffer,512,stdin); //read in command
   
		if (strncmp(buffer, "put[", 4)==0) //if put command is given
		{
			i = 0;
			while (buffer[i+5] != '\n') //write file name into file_name variable
			{
				file_name[i] = buffer[i+4];
				i++;
			}
			file_name[i] = '\0'; // null terminate file_name
			if(access(file_name, F_OK) == -1) //check to see if file exists
				printf("cannot find a file named %s in this directory\n", file_name);
			else //file exists
			{
				n = write(soc, "put\0", 4); //send put signal to server
				if (n < 0) 
				{
					perror("ERROR writing to socket\n");
					exit(1);
				}
				sleep(1);
				n = write(soc, file_name, strlen(file_name)); //send file name to server
				if (n < 0) 
				{
					perror("ERROR writing to socket\n");
					exit(1);
				}
				
				FILE *file; //file pointer
				file = fopen(file_name, "r"); //open file
				i = 0;
				bzero(buffer,512);
				while (ch != EOF) //read file contents into buffer
				{		
					ch = fgetc(file);
					buffer[i] = ch;
					i++;
					if(i==1023) // if file is too large terminate
					{
						printf("error. file too large\n");
						exit(1);
					}
				}
				buffer[i-1] = '\0'; //replace EOF with null terminator
				n = write(soc, buffer, strlen(buffer)); //send file contents to server
				if (n < 0) 
				{
					perror("ERROR writing to socket\n");
					exit(1);
				}
				bzero(buffer,512);
				n = read(soc, buffer, 512); //read ack

				if (n < 0)
				{
					perror("ERROR reading from socket\n");
					exit(1);
				}
				
			
			}
		}
		else if (strncmp(buffer, "get[", 4)==0) //if put command is given
		{
			i = 0;
			while (buffer[i+5] != '\n') //get file name to file_name
			{
				file_name[i] = buffer[i+4];
				i++;
			}
			file_name[i] = '\0'; //null terminate file_name
			n = write(soc, "get\0", 4); //send get command to server
			if (n < 0) 
			{
				perror("ERROR writing to socket\n");
				exit(1);
			}
			sleep(1);
			n = write(soc, file_name, strlen(file_name)); // send filename to server
			if (n < 0) 
			{
				perror("ERROR writing to socket\n");
				exit(1);
			}	
			i = 0;
			bzero(buffer,512);
			n = read(soc, buffer, 512); //read file contents or error message
			if (n < 0)
			{
				perror("ERROR reading from socket\n");
				exit(1);
			}
			if (strcmp(buffer, "file does not exist") == 0) //if file does not exist
			{
				printf("the file %s does not exist\n", file_name);
			}
			else //file exists
			{
				FILE *file; //file pointer
				file = fopen(file_name, "w"); //create file
				if (n < 0)
				{
					perror("ERROR reading from socket");
					exit(1);
				}
				for(i=0; i<strlen(buffer)-1; i++) //write file contents into file
					fputc(buffer[i], file);
				fclose(file); //close file
				printf("write complete\n"); //show complete
			}
		} 
		else if (strncmp(buffer, "quit", 4)==0) //if quit command it given
		{
			n = write(soc, "quit\0", 5);
			if (n < 0)
			{
				perror("ERROR writing to socket\n");
				exit(1);
			}
			n = close(soc);
		}
		else
			printf("Invalid Command\n");
		
	}
   return 0;
}

