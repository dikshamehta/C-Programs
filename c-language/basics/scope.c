#include<stdio.h>

int m(); //declaration of main
extern int x; //declaration of x
void xyz() {
	m();
}
int a;//defination + declaration of a
int m() { //definition + declartion of main()
	int c = a + 10;
	int d = x + 20;
	printf("%d %d", c, d);
	return 0;
}
int x = 20; //definition of x
int main() {
	return 0;
}
