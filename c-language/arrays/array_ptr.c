#include<stdio.h>
void func(int (*arr)[5]) {
	printf("%d %d\n",arr[0], arr[1]);
	//arr[0] = 2324;
	//arr[1] = 243;
}
int main() {
	int arr[5];
	arr[0] = 23;
	arr[1] = 34;
	printf("%d %d\n",arr, arr+1);
	int arr2[2][5];
	func(arr2);
	printf("%d %d\n", arr[0], arr[1]);

	int n = 10;
	int (*arr3)[n] = 100;
	printf("%d %d\n", arr3, arr3+1);
	return 0;
}
