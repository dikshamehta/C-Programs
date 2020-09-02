#include<stdio.h>

// struct <name/identifier> {
	//other data types
//};

struct Book {
	char *name;
	int pages;
};
typedef struct Book BOOK;
int main() {
	//usage syntax
	// struct <name/identifier> <varname>;
	struct Book b1;// 8 + 4 = 12 bytes -- size of constituent members
	BOOK b2;
	printf("%d\n", sizeof(b1)); // 16 bytest - actual size of struture is implementation dependent.

	//usage 
	// <struct-variable>.<constituent-variable> -- to access an constituent variable using dot(.) operator
	b1.name = "The monk who sold his Ferrari";// {'T', 'h', 'e'... '\0'} 
	b1.pages = 200;//

	char name[50]; //
	//name = "Another book"; - invalid operation
	printf("%s\n", b1.name);

	//pointer to an struct data type==============================================================================
	struct Book *ptr;
	BOOK* ptr2;
	
	ptr = &b1;
	ptr2 = &b2;
	
	//accessing constituent variable using pointer to an struct
	// arrow (->) operator is used
	ptr->name = "The 5 AM club";

	// Pointer arithmetic will work as usual Ptr + k == ptr + sizeof(struct Book) * k
	printf("%d %d\n", ptr, ptr+1);	
	return 0;
}
