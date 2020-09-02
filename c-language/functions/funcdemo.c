#include<stdio.h>

void fa() {
        int y = 10;
        printf("%d\n",y);
        fb(&y);
        printf("%d\n",y);
}
void fb(int* x) {
	
        *x = *x  + 10;
}
int main() {
       fa();
}
