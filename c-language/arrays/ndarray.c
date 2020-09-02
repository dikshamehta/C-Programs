#include<stdio.h>

int main() {
	int arr[2][5];
	// int arr[m][n] -- arr is an array of size m where each element is an array of size n
	// [
	//  [- - - - -],
	//  [- - - - -]
	// ]	
	int arr2[2][5][7];
	// int arr[m][n][p] -- arr is an array of size m where each element is an array of size n where each element is an array of size p
	// [
	//  [
	//   [- - - - - - -],
	//   [- - - - - - -],
	//   [- - - - - - -],
	//   [- - - - - - -],
	//   [- - - - - - -]
	//  ],
	//
	//  [
	//   [- - - - - - -],
	//   [- - - - - - -],
	//   [- - - - - - -],
	//   [- - - - - - -],
	//   [- - - - - - -]
	//  ]
	// ]
	
	//arr = 100;
	printf("%d %d\n",arr, arr + 1); //120

	//arr2 = 100;
	printf("%d %d\n",arr2, arr2 + 1); // 240

	printf("%d\n",sizeof(arr));
	return 0;
}
	
