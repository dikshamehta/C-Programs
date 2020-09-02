#include<stdio.h>

int main() {
	int arr[5] = {1,   2,   3, 4, 5};
	//           100, 104..........
	//     wrong 104, 10.... 
	// arr - pointer to the first element of the array and its type is the type of any element of the array
	// arr = 100 
	// arr + 1 == arr + 4;
	int i;
	for(i = 0; i<5; ++i) {
		printf("%d ",*(arr + i));
	}
	printf("\n");

	char (*ptr)[5] = 100; //Array pointer - declaration syntax
	printf("%d ",ptr);
	ptr = ptr + 1; // ptr + k === ptr + k * size_of_array_in_bytes
	printf("%d\n", ptr);
	return 0;
}

