//Static Variables in C

/*
  Static variables preserve their value even after they are out of scope.
  Retains memory during program execution

  A static variable inside a function keeps its value between invocations.

  A static global variable or a function is "seen" only in the file it's declared in
*/

//without static  output: 1 1
#include <stdio.h>

int fun()
{
  int count = 0;
  count++;
  return count;
}

int main()
{
  printf("%d ", fun());
  printf("%d ", fun());
  return 0;
}

//using static  output: 1 2
#include <stdio.h>

int fun()
{
  static int count = 0;
  count++;
  return count;
}

int main()
{
  printf("%d ", fun());
  printf("%d ", fun());
  return 0;
}
