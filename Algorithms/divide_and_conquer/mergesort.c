#include<stdio.h>

void merge(int *arr, int l, int mid, int r){
    int arr2[r-l+1];
    int p1 = l;
    int p2 = mid+1;

    int i = 0;
    while(p1<=mid && p2<=r){
        if(arr[p1]<=arr[p2]){
            arr2[i] = arr[p1];
            p1++;
        }
        else{
            arr2[i] = arr[p2];
            p2++;
        }
        i++;
    }

    //in case rest of the array is left
    if(p1<mid+1){
        for(int j=p1; j<=mid; j++){
            arr2[i] = arr[j];
            i++;
        }
    }
    else if(p2<r+1){
        for(int j=p2; j<=r; j++){
            arr2[i] = arr[j];
            i++;
        }
    }

    //copying elements back to first array
    for(int i=l; i<=r; i++){
        arr[i] = arr2[i-l];
    }
}


void mergesort(int *arr, int l, int r){
    //base case
    if(l>=r){
        return;
    }

    int mid = (l+r)/2;

    mergesort(arr, l, mid);
    mergesort(arr, mid+1, r);
    merge(arr, l, mid, r);
}


void display(int *arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n = 7;
    int arr[7] = {4,3,7,1,2,5,8};
    mergesort(arr, 0, n-1);
    // int a[] = {5,10,15,20,25,13,18,20,21};
    // merge(a, 0, 4, 8);
    display(arr, n);

    return 0;
}