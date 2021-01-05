Volatile qualifier keyword in embedded C
also in C++

Tell compiler to inhibit (disable) compilation optimization around read and write accesses
The compiler must not be allowed to make assumptions
Always get fresh value from memory and registers 



-Declare a global variable accessible by any interrupt service routine

-Declare a global variable accessible by two or more tasks

-Declare a pointer to a memory mapped-I/O peripheral register set
	(e.g. timer_t volatile * const p_timer)


/* 
Interrupts
DMA
Shared Resources
External Input
*/

Every embedded system has interupts

Data shared between interrupts (foreground and background code)

Reading and writing from hardware (peripheral device registers)
	has addresses
	status registers
	modified by hardware
	
#include <stdint.h>

#define SRAM_ADDRESS1 0x20000004U //'U' for unsigned 

int main (void)
{	
	uint32_t value = 0;
	volatile uint32_t *p = (uint32_t*) SRAM_ADDRESS1;  //by adding 'volatile' the compiler will not optimize and cause issues
	
	while(1)
	{
		value = *p;
		if (value ) break;
	}
	
	return 0;
}




const volatile int variable; //volatile int you are not allowed to write, but can be changed from outside


//threaded case
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

//This fails with -02 optimizations
//bool done = false;  
//this is where we can fix issues
volatile bool done = false;

void *tfunc(void * arg) {
	sleep(1);
	done = true;
	return NULL;
}

int main(){
	pthread_t t1;
	pthread_create(&t1, NULL,tfunc,NULL);
	
	printf("waiting\n");
	while(!done){}
	printf("moving on");
}



//Signal case
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

//This fails with -02 optimizations
//bool sigarrived = false;
//this is where we can fix issues
volatile sigarrived = false;

void handler(int sig){
	if sig == SIGINT){
		sigarrived = true;
	}
}

int main (){
	printf("Waiting. Press Ctrl-C to move on.\n";)
	signal(SIGINT, handler);
	while(!sigarrived) {}
	printf("moving on");
}	