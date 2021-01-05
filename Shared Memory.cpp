/*
	Shared Memory Model
	Create a shared memory segment in the address space by one process, read bt a different process (then delete)
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
	int shmid = shmget(key1024,0666| IPC_CREAT);
	
	//attach shared memory
	char *str = (char*) shmat(shmid,(void*)0,0);
	
	cout <<"Write Date:";
	
	gets(str);
	
	printf("Data written in memory: %s\n", str);
	
	//Detach shared memory from this writing process
	shmdt(str);
	
	return 0;
}


//Reader Process 
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
	shmctl(shmid, IPC_RMID,NULL);
	
	return 0;
}

