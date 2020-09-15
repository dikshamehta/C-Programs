/*
    min max using recursion 

    min(arr, l, r){
        if(l==r){
            return arr[l]
        }

        mid = (l+r)/2
        a = min(arr, l, mid)
        b = min(arr, mid+1, r)

        if(a>b){
            return b
        }
        else{
            return a
        }
    }
*/


#include<stdio.h>

int min(int *arr, int l, int r){
    if(l==r){
        return arr[l];
    }

    int mid = (l+r)/2;
    int a = min(arr, l, mid);
    int b = min(arr, mid+1, r);

    if(a>b){
        return b;
    }
    else{
        return a;
    }
}

int main(){
    int arr[5] = {-1, 3, 4, 1, 9};
    int l = 0;
    int r = 4;
    int m = min(arr, l, r);
    printf("%d\n", m);
    return 0;
}