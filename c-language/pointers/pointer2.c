#include<stdio.h>
int main(){
	//addition of pointer
	int* ptr = 100;
	int size = sizeof(int);
	ptr = ptr + 1;
	printf("%d\n", ptr);
	
	//subtraction of pointer
	int* ptr2 = 150;
	ptr2 = ptr2 - ptr; // ptr2-ptr1 = 46 => 46/4 = 11.5 ~ 11
        printf("%d\n", ptr2);	

	return 0;
}
