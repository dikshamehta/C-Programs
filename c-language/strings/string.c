#include<stdio.h>

int main() {
	//strings are the character array whose last element is the null character ('\0') - ASCII value = 0
	char arr[] = {'D', 'I', 'K', 'S', 'H', 'A'}; // it is not a string
	char str[] = {'D', 'I', 'K', 'S', 'H', 'A', '\0'}; // it is a string
	char str2[] = "DIKSHA"; //it is equivalent to the line above
	char *str3 = "DIKSHA";// char array "DIKSHA" will decay to a pointer

        "Diksha";// it will also exist in the memory when program is executed, expect that it will be of no use as 
	        // we cannot access it without a variable anywhere

	printf("%d %d\n", sizeof(str2), sizeof(str3));
	return 0;
}
