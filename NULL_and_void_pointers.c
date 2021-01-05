//NULL and void pointer notes

//c++99 uses NULL
//c++11 introduced nullptr

/*
	NULL pointer
	initalize pointer variables when pointer variable is not assigned to a valid memory address
	Check for null pointer before accessing any pointer variable
	Pass null pointer to function when we dont pass alid menory address
	Dereferencing a NULL pointer is undefined behavior
*/

#include <stdio.h>

int main(){
	int *p;
	p = NULL;
	int *pInt = NULL;
	
	if(p =! NULL)
		printf("The value of p is %u, p);
	return 0;
	else 
		{ /*some code */ };
}


/*
	Void Pointer
	Can point to any data type
	can't be referenced directly
	type casting is needed to return concrete data type

*/

#include <studio.h>

int main()
{
	int a = 1;
	double b=3.233;
	void *vp;
	
	vp = &a;
	printf("a = %d", *((int *)vp));
	vp = &b;
	printf("b = %d", *((double *)vp));
	return 0;
}
	