#include<stdio.h>
#include<stdlib.h>

int main() {
	// 1d - of size n
	int n = 10;
	void *ptr = malloc(sizeof(int) * n);//malloc will simply allocate the number of bytes given to it as paramter
	int *arr = (int*)ptr;// this conversion to use the memory allocated by malloc as an integer array
	//since arr is points to the first element of the memory allocated, therefore we can use arr as the name of array
	arr[0] = 10; // *(arr + 0) = 10;
	arr[1] = 100; // *(arr + 1) = 100;




	//Method 1 to allocate dynamic multidimensional array
	//2d - of shape [m][n] -- array of size m where each element is an array of size n
	int m = 2;
	n = 4;
	// below is the mental picturization of the 2d array that we want to create
	// [ 
	//  [- - - -],
	//  [- - - -]
	// ]
	
	// legend - '-' - an element of normal datatype
	//          '*' - a pointer
	// the method that we are using, uses an array of pointers of size m
	// each element points to(stores the adrress of) an array of size n
	// 1. allocate memory for an array of pointers of size m
	// 2. initialze the array by giving each element an adrress of an array of size n
	//address 100     108
	//        [*       *]
	//         |       |
	//    500 [-]  700[-]
	//    504 [-]  704[-]
	//    508 [-]  708[-]
	//    512 [-]  712[-]
	void *ptr1 = malloc(sizeof(int*) * m);
	int **arr2d = (int**)ptr1;

	for(int i=0;i<m;++i) {
		void* ptr2 = malloc(sizeof(int) * n);
		arr2d[i] = (int*)ptr2;
	}

	//using vla
	int *vlaarr2d[m]; //pointer array
	int xyz[m];//normal integer array



}
