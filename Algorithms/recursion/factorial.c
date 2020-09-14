#include<stdio.h>

int fact(int n){
    if(n==1){
        return 1;
    }
    return fact(n-1)*n;
}

int main(){
    int n = 4;
    int f = fact(n);
    printf("%d\n", f);
    return 0;
}