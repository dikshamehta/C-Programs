#include<stdio.h>

int fibo(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fibo(n-2) + fibo(n-1);
}

int fibo_itr(int n){
    int a = 0;
    int b = 1;

    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    
    int c;
    for(int i=0; i<n-1; i++){
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int n = 6;
    printf("%d\n",fibo_itr(n));
    return 0;
}