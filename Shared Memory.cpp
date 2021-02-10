/*
	Shared Memory Model
	Create a shared memory segment in the address space by one process, read bt a different processes (different programs) (then delete)
	
	
	shmget(): allocates a shared memory segment and returns identifier for said segment.
		
		#include <sys/ipc.h>
		#include <sys/shm.h>
		
		int shmget(key_t key, size_t size, int shmflg); //If shmflg is set to 0, IPC_PRIVATE
											IPC_CREAT
											IPC_EXCL
	
	shmat(): attaches shared memory segment(which has shmid) to the address space of the calling process(which has shmaddr).
	
	shmdt(): detaches shared memory segment(which has shmid) to the address space of the calling process(which has shmaddr).
	
	shmctl(): performs control operations on segment with shmid, and used to mark shared memory segment for DESTRUCTION.
		int shmctl(int shmid, int cmd, struct shmid_ds *buf);
	
	ftok(): convert pathname and project identifier for IPC key (system V)
		#include <sys/types.h>
		
		key_t ftok(const char *pathname, int proj_id)
	
*/


//Writing Process
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
	//create a unique key
	key_k key = ftok("shmfile", 65);
	
	//create identifier for shmid
	int shmid = shmget(key1024,0666 | IPC_CREAT);
	
	//attach shared memory
	char *str = (char*) shmat(shmid,(void*)0,0);
	
	cout <<"Write Date:";
	
	gets(str);
	
	printf("Data written in memory: %s\n", str);
	
	//Detach shared memory from this writing process
	shmdt(str);
	
	return 0;
}


//Reading Process (segment attaches to this)
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
	//Generate a new key
	key_k key = ftok("shmfile", 65);
	
	//returns identifier in shmid
	int shmid = shmget(key1024,0666| IPC_CREAT);
	
	//attach shared memory to writing process
	char *str = (char*) shmat(shmid,(void*)0,0);
	
	printf("Shared memory reads: %s\n", str);
	
	//Detach the shared memory
	shmdt(str);
	
	//destroy the shared memory
	shmctl(shmid, IPC_RMID, NULL);
	
	return 0;
}



