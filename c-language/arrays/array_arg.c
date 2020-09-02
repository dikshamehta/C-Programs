#include<stdio.h>
#define SIZE 1000
void abc(int *arr) {
	printf("%d %d\n", arr, arr+1);
}

void xyz(int arr[]) {
	printf("%d %d\n", arr, arr+1);
}

void pqr(int arr[SIZE]) {
	printf("%d %d\n", arr, arr+1);
}

void mnp(int (*arr)[SIZE]) {// the int pointer(after array decay) that will be passed to this function will be type casted to array pointer
	printf("%d %d\n", arr, arr+1);
}

void asfdas(char *arr) { // the int pointer(after array decay) that will be passed to this function will be type casted to char pointer
}

int sum(int *arr, int n) {
	int sum = 0;
	for (int i=0;i<n;++i) {
		sum += arr[i]; // *(arr + i);
	}
	return sum;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	printf("%d\n",arr); 
	// the arr passed to the functions as arg is a pointer of type int after decaying.
	abc(arr);
	xyz(arr);
	pqr(arr);
	mnp(arr);
	asfdas(arr);
	sum(arr, 5);
	return 0;
}
