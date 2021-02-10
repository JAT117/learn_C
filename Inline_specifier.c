//Inline Specifier for Functions in C

/*
Inline functions are those whose definitions are small and can be substituted at the place where the function call happened.
Provides a hint to the compiler to perform function inlining(optimization). 
Function substitution is a decided by the compiler and may be ignored.

'functions with tiny definitions can be optimized, hope the compiler takes the hint'

Supported by C99 but not earlier variants like K&R

*/

//for C
#include <stdio.h> 
static inline int foo() // Inline function in C 
{ 
	return 2; 
} 

int main() 
{ 
	int ret; 
	ret = foo(); // inline function call 

	printf("Output is: %d\n", ret); 
	return 0; 
} 


//for C++
#include <iostream>
using namespace std;
inline int cube(int s)
{
	return s*s*s;
}

int main
{
	cout << "The cube of 5 is " << cube(5) << endl;
	return 0;
}
	
