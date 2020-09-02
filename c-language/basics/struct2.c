//make a structure with 1 int and 1 pointer that points to structure itslef

#include<stdio.h>

struct Node{
	int data;
	struct Node* next;
}n;

struct Node n1;

int main(){
	n1.data = 14;
	n1.next = NULL; // NULL is defined in stdio.h
	//Initialization of structure data type
	struct Node n2 = {16, NULL};
	
	struct Node arr[5];
	struct Node b[]={{16, NULL}, {18, NULL}};
	return 0;
 }
