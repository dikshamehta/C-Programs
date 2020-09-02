#include<stdio.h>

int main() {
	int *p = 100;
	int (*p1)[5] = 100;

	p = p + 1;
	p1 = p1 + 1;
	printf("%d %d",p,p1);
	return 0;
}
