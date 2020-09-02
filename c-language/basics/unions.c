#include<stdio.h>

union ut {
	unsigned int a;
	char c;
};// at a time only one of the constituent variables can be used
int main() {
	union ut u;
	printf("%d\n", sizeof(u));
	// | | | | |
	u.a = 0x0000FF14; // 0 0 F F
	// Byte 3      Byte 2       Byte 1         Byte 0
	//0000 0000    0000 0000    1111 1111     0001 0100
	printf("%p %p", u.a, u.c);
	
	return 0;
}
