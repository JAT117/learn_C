////////////////////
/*
	mmap(2) example
	
	mapps memory files or deviced into memory, used for memory mapped file IP
	
	void *mmap(void *start, size_t length, int prot, int flags, int fd, off_t offset); 
	
	https://www.tutorialspoint.com/unix_system_calls/mmap.htm
	
*/

#include <sys/types.h>
#include <sys/mman.h> //needed header for mmap
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>
#include <stdint.h>

#define PAGESIZE 4096

int v = 5;

int main(int argc, char** argv)
{
	uint8_t *shared_memory = mmap(NULL,
								PAGESIZE, PROT_READ|PROT_WRITE,
								MAP_SHARED|MAP_ANONYMOUS, -1, 0);
	
	*shared_memory = 34
	
	if(fork() == 0)
	{
		*shared_memory = 15;
		v = 80;
	}
	else
	{
		wait(NULL);
	}
	
	printf("Not Shared. %i\n" ,v);	
	printf("Shared. %i\n" ,*shared_memory);	
}
