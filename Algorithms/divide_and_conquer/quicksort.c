/*
Example:

    arr = [70 80 90 55 25 35 99 88 45 62]
    pivot = 70
    pos = 0 // position of pivot

        j = pos + 1 = 1
        arr[j] = 80, 80 > 70 - do nothing

        j = 2
        arr[j] = 90, 90 > 70 - do nothing

        j = 3
        arr[j] = 55, 55 < 70 {
            pos = pos + 1 = 1
            swap(arr[pos], arr[j]) // ie 55 and 80
        }
        [70 55 90 80 25 35 99 88 45 62]

        j = 4
        arr[j] = 25, 25 < 70 {
            pos = pos + 1 = 2
            swap(arr[pos], arr[j]) // ie 25 and 90
        }
        [70 55 25 80 90 35 99 88 45 62]

        j = 5
        arr[j] = 35, 35 < 70 {
            pos = pos + 1 = 3
            swap(arr[pos], arr[j]) // ie 35 and 80
        }
        [70 55 25 35 90 80 99 88 45 62]

        j = 6
        arr[j] = 99 - 99 > 70 - do nothing

        j = 7
        arr[j] = 88 - 88 > 70 - do nothing

        j = 8
        arr[j] = 45 - 45 < 70 {
            pos = pos + 1 = 4
            swap(arr[pos], arr[j]) // ie 45 and 90
        } 
        [70 55 25 35 45 80 99 88 90 62]

        j = 9
        arr[j] = 62 - 62 < 70 {
            pos = pos + 1 = 5
            swap(arr[pos], arr[j]) // ie 62 and 80
        }
        [70 55 25 35 45 62 99 88 90 80]
    
    swap(arr[pos], arr[l])
    [62 55 25 35 45 70 99 88 90 80]

    return pos


complexity : O(nlog(n)) in average case and O(n^2) int worst case 
expression: T(n) = T(pos-l) + T(r-pos) + n
best case : pos-l = r-pos = n/2----> T(n) = T(n/2) + T(n/2) + n----> O(nlog(n))
worst case : pos-l = 0; r-pos = n-1---->T(n)   T(0) + T(n-1) + n----> O(n^2)


*/

#include<stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *arr, int l, int r) {
    int pos = l;
    int pivot = arr[l];

    for(int j=pos+1; j<=r; j++){
        if(arr[j]<pivot){
            pos = pos + 1;
            swap(&arr[pos], &arr[j]);
        }
    }
    swap(&arr[l], &arr[pos]);
    return pos;
}

void quick_sort(int *arr, int l, int r) {
    if(l >= r) {
        return;
    }
    int pos = partition(arr, l, r);
    quick_sort(arr, l, pos-1);
    quick_sort(arr, pos+1, r);
}

void display(int *arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {70,80,90,55,25,35,99,88,45,62};
    quick_sort(arr, 0, 9);
    display(arr, 10);

    return 0;
}
