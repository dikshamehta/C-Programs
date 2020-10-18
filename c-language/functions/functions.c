#include<stdio.h>
void xyz() {
	printf("hello \n");
}
void perform_action(void (*action)()) {
	(*action)();
}

int main() {
	//syntax
	//<return_type> <identifier>(<args>) {
	//	code here  
	//}
	//
	//--> In c functions are 'called only by value'. 
	//The equivalent work of call by reference is done by passing pointers to a function
	//
	//====================================== Function pointers/pointer to a function =============================================================
	//functions are stored in the text/code segment - and text segment is a part of the memory so it has an adress. 
	//Therefore it is possible to store the address of a function in a variable and the variables that store these address 
	//are called 'function pointers'.
	//
	//syntax -
	//<return type> (*identifier)(arg types)
	//ex - void (*ptr)(int) // ptr is now a function pointer
	//to call call functions using ptr use - (*ptr)(args);
	//
	//NOTE: functions names can be thought of as a type of variables
	void (*ptr)(void);
	ptr = &xyz;
	printf("%p\n", ptr);

	xyz();
	
	(*ptr)();

	ptr();

	perform_action(&xyz);
}
