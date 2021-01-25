//open vs fopen


//open (POSIX syscalls) lower level call, fopen actually uses open
//every open file has a file descriptor

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	FILE *fd_to_read = open("sometext.txt", O_RDONLY); //syscall with options
	FILE *fd_to_write = open("newtext.txt", O_WDONLY | O_CREAT, S_IRUSR | S_IWUSR);
	
	if (fd_to_read == -1 || fd_to_write == -1)
	{
		printf("One file would not open\n");
		return -1;
	}
	
	char c;
	int bytes;
	while((bytes = read(fd_to_read, &c, sizeof(c))) > 0)
	{
		if (c == '.'){
			c = '!';
		}
		write(fd_to_write, &c, sizeof(c));
	}
	
	close(fd_to_read);
	close(fd_to_write);
}


//library call fopen() using one character at a time (works on windows)
//functionally equivalent to the above syscall example
//fopen uses buffering and is much faster than open
//uses fewer system calls by reading and writing in chunks

#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *file_to_read = fopen("sometext.txt", "r"); //pointer to file with read mode
	FILE *file_to_write = fopen("newtext.txt", "w");
	
	if (file_to_read == NULL || file_to_write == NULL)
	{
		printf("One file would not open\n");
		return -1;
	}
	
	char c;
	while((c=fgetc(file_to_read)) != EOF )
	{
		if (c == '.'){
			c = '!';
		}
		fputc(c, file_to_write);
	}
	
	fclose(file_to_read);
	fclose(file_to_write);
}

/* fscanf fread

fputs fprintf fwrite */