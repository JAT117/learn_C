Extern qualifier keyword in C

Extends the visibility of C variables and functions over the whole program. 

Consider them global scope variables. 

Variables with extern keyword are only declared not defined.

Declaration: declare a function or variables exists somewhere in the program,
memory is not allocated for them. Declarables can be declared multiple times, but only defined once.

	extern int bar;
	extern int g(int, int);
	double f(int, double); // extern can be omitted for function declarations
	class foo; // no extern allowed for type declarations

Definition: defines a variable of function and allocaes memory

	int bar;
	int g(int lhs, int rhs) {return lhs*rhs;}
	double f(int i, double d) {return i+d;}
	class foo {};

int foo(int arg1, char arg2);


extern int foo(int arg1, char arg2);


int var;
int main(void)
{
   var = 10;
   return 0;
}

extern int var;
int main(void)
{
  return 0;
}


extern int var;
int main(void)
{
  var = 10;
  return 0;
}

#include "somefile.h"
extern int var;
int main(void)
{
 var = 10;
 return 0;
}

extern int var = 0;
int main(void)
{
 var = 10;
 return 0;
}

#include <stdio.h>
extern int x = 32;
int b = 8;
int main() {
   auto int a = 28;
   extern int b;
   printf("The value of auto variable : %d\n", a);
   printf("The value of extern variables x and b : %d,%d\n",x,b);
   x = 15;
   printf("The value of modified extern variable x : %d\n",x);
   return 0;
}