#include<stdio.h>
#include<stdlib.h>
int main() {
	int *ptr = (int*) malloc(sizeof(int));
	//work done here
	free(ptr); // free(void*) - 
	// malloc and calloc allocate some extra space(other than the amount that is requested) when they are called
	//             <--16 bytes--><--8 bytes -->
	// malloc(8) - ||   Header  ||   data    || 
	// header stores the information about the size of the data that is allocated
	// malloc returns the first address of the data portition
	//
	// free takes the first address of the data portition as argument 
	// It then checks the header portition to find the size of the data portition and the frees the space accordingly
	// free will take as argument only that ptr that has been allocated by malloc or calloc. - 
	// data portition ptr = 100, 100 - 16 = 84 will be the first address of the header part.
	// if any other ptr is passed to free then its working will be undefined. 
	//
	//
	// typdef unsigned long size_t
	// realloc - void* realloc(void* ptr, size_t size)
	// ptr - the first address of the memory (allocated by malloc or calloc) that we need to extend or reduce 
	// size - the new size in bytes
	// Why do we need realloc when free and malloc and calloc are present ??
	return 0;	
}
