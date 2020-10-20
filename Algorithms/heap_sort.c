#include<stdio.h>
#include"../DataStructures/trees/max_heap.c"

void heapSort(int *arr, int maxcap){
    //initializing heap
    HEAP *h = newHeap(maxcap);

    //putting values in heap 
    for(int i=0; i<maxcap; i++){
        insertion(h, arr[i]);
    }

    for(int i=0; i<maxcap; i++){
        arr[maxcap-i-1] = deletion(h);
    }
}

void displaySortedArray(int *arr, int maxcap){
    for(int i=0; i<maxcap; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(){
    int maxcap = 8;
    int arr[] = {6,8,3,5,9,1,4,2};

    heapSort(arr, maxcap);

    displaySortedArray(arr, maxcap);
}