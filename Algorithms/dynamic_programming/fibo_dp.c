#include<stdio.h>

int fibo_dp(int *arr, int n){
    if(n == 1){
        arr[n] = 0;
    }
    else if(n == 2){
        arr[n] = 1;
    }
    else if(arr[n]==-1){
        arr[n] = fibo_dp(arr, n-1) + fibo_dp(arr, n-2);
    }
    return arr[n];
}

int main(){
    int n = 10;
    int arr[n+1];

    for(int i=0; i<n+1; i++){
        arr[i] = -1;
    }

    printf("%d",fibo_dp(arr, n));
    return 0; 
}