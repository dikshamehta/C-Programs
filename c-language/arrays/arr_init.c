#include<stdio.h>

int main() {
	int arr[] = {1, 2, 3, 4, 5}; //initialization of 1d array
	int arr2d[][6]= { {1, 2, 3, 4, 5, 6},
			  {7, 8, 9, 10, 11, 12}};

	int arr2d2[][3] = {1, 2, 3, 4, 5, 6}; // [ [1,2,3],[4,5,6] ]

	//special cases
	int arr2d3[2][3] = {{1,2,3}, {5,6,7}, {8,9,10}}; // the compiler will ignore the excess elements but will give warning
	printf("%d\n", arr2d3[2][0]);

	return 0;
}
