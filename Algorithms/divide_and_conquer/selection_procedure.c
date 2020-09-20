//input : arr and k 
//output: position of kth smallest integer
//complexity : worst case: T(n) = T(n-1) + n----->O(n^2)
//             average case: T(n) = T(n/2) + n----->O(n)
#include<stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *arr, int l ,int r){
    int pos = l;
    int pivot = arr[l];

    for(int j=pos+1; j<=r; j++){
        if(arr[j]<pivot){
            pos = pos+1;
            swap(&arr[pos], &arr[j]);
        }
    }
    swap(&arr[pos], &arr[l]);
    return pos;
}

int selection(int *arr, int l, int r, int k){
    if(l>=r){
        return l;
    }
    int pos = partition(arr, l, r);
    if(pos+1 == k){
        return pos;
    }
    else if(pos+1>k){
        return selection(arr, l, pos-1, k);
    }
    else{
        return selection(arr, pos+1, r, k);
    }

}

int main(){
    int k = 7;
    int arr[] = {70,80,90,55,25,35,99,88,45,62};
    int pos = selection(arr, 0, 9, k);
    printf("%d\n", arr[pos]);
    return 0;
}