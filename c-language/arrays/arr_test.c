#include<stdio.h>

int get_len() {
	return 20;
}
int main() {
	int arr[5];
	int *p = &arr;
	printf("%d %d\n", arr, p);
	int n = get_len();
	int arr2[n];
	printf("%d\n", sizeof(arr2));
	return 0;
}
