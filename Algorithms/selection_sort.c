/* //n = size of array
min = arr[0];
int index;
for(int j=0; j<n-1; j++){
    for(int i = j; i<n-1; i++){
        if(arr[i]<=min){
            min = arr[i];
            index = i;
        }
    }
    swap();
    arr[j] = min;
}
*/

#include<stdio.h>
#define DEBUG

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp; 
    // *x = *x ^ *y;
    // *y = *x ^ *y;
    // *x = *x ^ *y;
}

void display(int *arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int *arr, int n){
    for(int i=0; i<n; i++){
        int index = i;
        for(int j=i; j<n; j++){
            if(arr[j]<arr[index]){
                index = j;
            }
        }
        swap(&arr[i], &arr[index]);
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

    selection_sort(arr, n);
    display(arr, n);

    return 0;
}