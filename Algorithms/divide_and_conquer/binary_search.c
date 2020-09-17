#include<stdio.h>

int binary(int *arr,int l, int r, int s){
    //base case
    if(l>r){
        return -1;
    }

    int mid = (l+r)/2;

    if(s == arr[mid]){
        return mid;
    }
    else if(s>arr[mid]){
        return(binary(arr, mid+1, r, s));
    }
    else{
        return(binary(arr, l, mid-1, s));
    }
}

int binary_itr(int *arr, int l, int r, int s){
    while(l<=r){
        int mid = (l+r)/2;
        if(s == arr[mid]){
            return mid;
        }
        else if(s > arr[mid]){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return -1;
}

int main(){
    int n = 5;
    int arr[5] = {1,2,3,5,7};
    int s = 3;
    int index = binary(arr, 0, n-1, s);
    printf("%d\n", index);
    return 0;
}
