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

/* Nullptr
	c++11 introduced the nullptr
	The nullptr keyword is a "pointer literal"
	
	
*/


//ex: need for nullptr
#include <bits/stdc++.h>
using namespace std;
int fun(int N) { cout << "fun(int)";}
int fun(char *s) {cout << "fun(char *)";}
int main() {fun(NULL);}

#include <stdio.h>
int main(){int x = NULL;}

#include <stdio.h>
int main(){int x = nullptr;}


#include <stdio.h>
using namespace std;
int main()
{
	int *ptr = nullptr;
	if(ptr) = { cout << "true";}
	else { cout << "false";}  //this is output
}
	

//type nullptr_t
#include <bits/stdc++.h>
using namespace std;

int main()
{
		nullptr_t np1, np2;
		
		//is this even allowed?
		cout << sizeof(nullptr_t) << endl;
		cout << sizeof(np1) << endl;
		cout << sizeof(np2) << endl;
		
		if(np1 >= np2)
			cout << "can compare" <<endl;
		else
			cout << "cannot compare" << endl;
		
		char *x = np1;
		if(x == nullptr)
			cout << "x is null" <<endl;
		else
			cout << "x isn't null" << endl;	
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
	void *vp; //void pointer 
	printf(sizeof(void vp);
	vp = &a;
	printf("a = %d", *((int *)vp));
	vp = &b;
	printf("b = %d", *((double *)vp));
	return 0;
}

////////////////////////////////////
