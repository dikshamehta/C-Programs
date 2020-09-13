/*
arr = [6 3 5 2] 
iteration 1:
    if arr[0]>arr[1]:
        swap = [3 6 5 2]

    if arr[1]>arr[2]:
        swap = [3 5 6 2]

    if arr[2]>arr[3]:
        swap = [3 5 2 | 6]

iteration 2:
    if arr[0]>arr[1]:
        swap = [3 5 2 | 6]

    if arr[1]>arr[2]:
        swap = [3 2 | 5 6]

iteration 3:
    if arr[0]>arr[1]:
        swap = [2 | 3 5 6]
*/

#include<stdio.h>
#define DEBUG 

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp; 
}

void display(int *arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void bubble_sort(int *arr, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main(){

    #ifdef DEBUG
    stdin = fopen("input.txt", "r");
    //stdout = fopen("output.txt", "w");
    #endif

    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr, n);
    display(arr, n);

    return 0;
}

