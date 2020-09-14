#include<stdio.h>

int sum(int n){
    if(n==1){
        return 1;
    }
    return sum(n-1)+n;
}

int sum_itr(int n){
    int s = 0;
    for(int i=1; i<=n; i++){
        s = s + i;
    }
    return s;
}

int main(){
    int n = 10;
    int s = sum_itr(n);
    printf("%d", s);
    return 0;
}