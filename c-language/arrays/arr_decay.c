#include<stdio.h>

int main() {
	int arr[5];
	printf("%d\n",arr);//arr will decay to a pointer
	int *p = arr + 1;// arr will decay to a pointer
	printf("%d\n",p);

	//cases where array does not decay
	//case 1
	printf("%d\n",sizeof(arr));

	//case 2
	printf("%d %d\n",arr, &arr); //if using & the array decays then
       	//the address printed here will be different but if it does not decay
	//addresss printed will be same
	
	//case 3 - when the array is in the form of string literal;
	char arr[] = "Some string";

	return 0;
}
