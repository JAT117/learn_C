//Inline Specifier for Functions in C

/*
Inline functions are thoe whose definitions are small and be substituted at the place where the function call happened.
Provides a hint to the compiler to perform function inlining(optimization). 
Function substitution is a decided by the compiler and may be ignored.

Supported by C99 but not earlier variants like K&R

*/

#include <stdio.h> 

// Inline function in C 
static inline int foo() 
{ 
	return 2; 
} 

// Driver code 
int main() 
{ 

	int ret; 

	// inline function call 
	ret = foo(); 

	printf("Output is: %d\n", ret); 
	return 0; 
} 
