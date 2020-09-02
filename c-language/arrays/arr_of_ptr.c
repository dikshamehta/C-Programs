#include<stdio.h>

int main() {
	int (*ptr)[5]; // array pointer

	int *arr[5]; // array of pointers
	int a = 10, b = 20, c =  30, d = 40, e = 50;
	arr[0] = &a;
	arr[1] = &b;
	arr[2] = &c;
	arr[3] = &d;
	arr[4] = &e;
	return 0;
}
