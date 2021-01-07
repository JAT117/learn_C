Synchronization primatives

new data type with ingeger value >= 0
threads and processess need to share information to perform tasks


mutex
condation var
monitors
barriers
semaphores

Its an unsigned int, changes are atomic
2 operations:
	wait()
	post() //also called signal
	
	
	wait(){
		while(1){
			atomic{
			if(v > 0){
				v--;
				return;
			}
		}
	}
	
	
	post(){
		atomic {
			v++;
			return;
		}
	}
	
Binary semaphore


wait()
//critical section
post() or signal()

////////////////////////////



semaphore s = K;
 wait (semaphore s) //wait until s > 0, then s = s - 1
 signal(semaphore s) // s = s +1, one wait() process may now proceed
 
 signal(s)_i < wait(s)_i+k