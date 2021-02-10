/*
Malloc(), Calloc(), Realloc(), and Free()
C is a structured language
We need to know the sizes of allocated memory before we requesition


malloc(): memory allocation 
	Dynamically allocates a large block of memory with a specified size.
	Returns pointer of type void which can be cast into a pointer of any form.
	Pointer holds the address of the first byte in allocated memory


	ptr = (cast-type*) malloc(n * byte-size)

	int *ptr = (int*)malloc(5 * sizeof(int))
				5 * sizeof(int) is 4 bytes = 20 bytes
*/				
				
	//malloc() example
	#include <stdio.h> 
	#include <stdlib.h> 
	  
	int main() 
	{ 
		// This pointer will hold the 
		// base address of the block created 
		int* ptr; 
		int n, i; 
	  
		// Get the number of elements for the array 
		n = 5; 
		printf("Enter number of elements: %d\n", n); 
	  
		// Dynamically allocate memory using malloc() 
		ptr = (int*)malloc(n * sizeof(int)); 
	  
		// Check if the memory has been successfully 
		// allocated by malloc or not 
		if (ptr == NULL) { 
			printf("Memory not allocated.\n"); 
			exit(0); 
		} 
		else { 
	  
			// Memory has been successfully allocated 
			printf("Memory successfully allocated using malloc.\n"); 
	  
			// Get the elements of the array 
			for (i = 0; i < n; ++i) { 
				ptr[i] = i + 1; 
			} 
	  
			// Print the elements of the array 
			printf("The elements of the array are: "); 
			for (i = 0; i < n; ++i) { 
				printf("%d, ", ptr[i]); 
			} 
		} 
		return 0; 
	} 

calloc(): contiguous allocation, similar to malloc(), initalizes each block with a default value '0'
	
		ptr = (cast-type*)calloc(n, element-size);
		
		ptr = (float*) calloc(25, sizeof(float));
	
	//calloc() example
	#include <stdio.h> 
	#include <stdlib.h> 

	int main() 
	{ 

		// This pointer will hold the 
		// base address of the block created 
		int* ptr; 
		int n, i; 

		// Get the number of elements for the array 
		n = 5; 
		printf("Enter number of elements: %d\n", n); 

		// Dynamically allocate memory using calloc() 
		ptr = (int*)calloc(n, sizeof(int)); 

		// Check if the memory has been successfully 
		// allocated by calloc or not 
		if (ptr == NULL) { 
			printf("Memory not allocated.\n"); 
			exit(0); 
		} 
		else { 

			// Memory has been successfully allocated 
			printf("Memory successfully allocated using calloc.\n"); 

			// Get the elements of the array 
			for (i = 0; i < n; ++i) { 
				ptr[i] = i + 1; 
			} 

			// Print the elements of the array 
			printf("The elements of the array are: "); 
			for (i = 0; i < n; ++i) { 
				printf("%d, ", ptr[i]); 
			} 
		} 

		return 0; 
	} 

Free(): de-allocates memory, responsibility of programmer to release memory no longer needed.
	
	free(ptr);
	
	
	//free() example
	#include <stdio.h> 
	#include <stdlib.h> 
	  
	int main() 
	{ 
	  
		// This pointer will hold the 
		// base address of the block created 
		int *ptr, *ptr1; 
		int n, i; 
	  
		// Get the number of elements for the array 
		n = 5; 
		printf("Enter number of elements: %d\n", n); 
	  
		// Dynamically allocate memory using malloc() 
		ptr = (int*)malloc(n * sizeof(int)); 
	  
		// Dynamically allocate memory using calloc() 
		ptr1 = (int*)calloc(n, sizeof(int)); 
	  
		// Check if the memory has been successfully 
		// allocated by malloc or not 
		if (ptr == NULL || ptr1 == NULL) { 
			printf("Memory not allocated.\n"); 
			exit(0); 
		} 
		else { 
	  
			// Memory has been successfully allocated 
			printf("Memory successfully allocated using malloc.\n"); 
	  
			// Free the memory 
			free(ptr); 
			printf("Malloc Memory successfully freed.\n"); 
	  
			// Memory has been successfully allocated 
			printf("\nMemory successfully allocated using calloc.\n"); 
	  
			// Free the memory 
			free(ptr1); 
			printf("Calloc Memory successfully freed.\n"); 
		} 
	  
		return 0; 
	} 
			
/*			
Realloc(): re-allocation of previously allocated memory

	int *ptr = (int*)malloc(5*size(int)) //allocates 20 bytes
	ptr = realloc(ptr, 10*sizeof(int)); //reallocates to 40bytes
	where ptr is reallocated with new size 'newSize'.
*/
	//realloc() example	
	#include <stdio.h> 
	#include <stdlib.h> 

	int main() 
	{ 

		// This pointer will hold the 
		// base address of the block created 
		int* ptr; 
		int n, i; 

		// Get the number of elements for the array 
		n = 5; 
		printf("Enter number of elements: %d\n", n); 

		// Dynamically allocate memory using calloc() 
		ptr = (int*)calloc(n, sizeof(int)); 

		// Check if the memory has been successfully 
		// allocated by malloc or not 
		if (ptr == NULL) { 
			printf("Memory not allocated.\n"); 
			exit(0); 
		} 
		else { 

			// Memory has been successfully allocated 
			printf("Memory successfully allocated using calloc.\n"); 

			// Get the elements of the array 
			for (i = 0; i < n; ++i) { 
				ptr[i] = i + 1; 
			} 

			// Print the elements of the array 
			printf("The elements of the array are: "); 
			for (i = 0; i < n; ++i) { 
				printf("%d, ", ptr[i]); 
			} 

			// Get the new size for the array 
			n = 10; 
			printf("\n\nEnter the new size of the array: %d\n", n); 

			// Dynamically re-allocate memory using realloc() 
			ptr = realloc(ptr, n * sizeof(int)); 

			// Memory has been successfully allocated 
			printf("Memory successfully re-allocated using realloc.\n"); 

			// Get the new elements of the array 
			for (i = 5; i < n; ++i) { 
				ptr[i] = i + 1; 
			} 

			// Print the elements of the array 
			printf("The elements of the array are: "); 
			for (i = 0; i < n; ++i) { 
				printf("%d, ", ptr[i]); 
			} 
			free(ptr); 
		} 
		return 0; 
	} 

