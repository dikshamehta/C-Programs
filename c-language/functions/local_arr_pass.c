#include<stdio.h>
void xyz(int *arr, int n) {
	printf("%d\n", arr[0]);
}

int* pqr() {
	int a = 10;
	return &a;
}

int (*mnp())[4] {
	int (*ptr)[4];
	return ptr;
}
int main() {
	int arr[] = {1, 2, 3, 4};
	xyz(arr, 4);

	int arr2[][3] = {1, 2, 3, 4, 5, 6};
	int *ptr = pqr();
	printf("%d",*ptr);
	return 0;
}

//Syntax to return a pointer -- <return type>* function_name(params) {}
//Syntax to return an array pointer -- <return_type> (*function_name(params))[SIZE] { code.... } 
//example - int (*xyz(int a))[5] { some code ... }

//   _____
//   |main|- a - array1 , b - array 2 , c - array pointer
//   |add |- c = a + b - return &c;
//
//   ______
//   |main|- 
