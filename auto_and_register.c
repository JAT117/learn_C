Auto and Register storage class specifiers.

Lifetime: Block
Scope: Block

Auto:
	This is not the same as "auto" type specifier in C++11 which allocates variables as an inferred data type
	Stands for automatic storage class
	Default storage class
	Initial value is garbage
	Called only for local variables
	Variables are deleted when the block exits
	

	//auto example, output is 0 0 0 0
	#include<stdio.h>

	void increment(void);

	int main()
	{
	   increment();
	   increment();
	   increment();
	   increment();
	   return 0;
	}
	 
	void increment(void)
	{
	   auto int i = 0 ; //if you replaces auto with static the output would be 0 1 2 3
	   printf ( "%d ", i ) ;
	   i++;
	}

	
Register:
	Variables stored in registers are faster to access than when stored in RAM.
	Used to store local variables inside function or blocks into CPU registers instead of RAM to have faster access.
	Useful for heavily accessed variables and improving performance during runtime.
	Compilers are not required to honor register, and will only store in a free hareware register if available.
	Useful for counters.
	Register cannot be used with static.
	Register cannot be a global scope and can only be used within a block.
	You cannot take the address of a variable declared with register
	
	
	register int count;
	
	
	
	#include <stdio.h>
	int main()
	{
	   register int i;
	   int arr[5];// declaring array
	   arr[0] = 10;// Initializing array
	   arr[1] = 20;
	   arr[2] = 30;
	   arr[3] = 40;
	   arr[4] = 50;
	   for (i=0;i<5;i++)
	   {
		  // Accessing each variable
		  printf("value of arr[%d] is %d and at location %x\n", i, arr[i], &arr[i]);
	   }
	   return 0;
	}
	
	//error: address of register variable ‘i’ requested
	#include <stdio.h> 
	int main() 
	{ 
		register int i = 10; 
		int* a = &i; 
		printf("%d", *a); 
		getchar(); 
		return 0; 
	} 
	
