#include<stdio.h>
#define MAXCAP 15

int arr[MAXCAP];

int size = 0;

void init(){
    for(int i=0; i<MAXCAP; i++){
        arr[i] = -1;
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify_up(int pos){
    int child = pos;
    int parent = (child - 1)/2;

    while(arr[child] > arr[parent]){
        swap(&arr[child], &arr[parent]);
        child = parent;
        parent = (parent - 1)/2;
    }
    return;
}

void insertion(int data){
    if(size==MAXCAP){
        printf("overflow");
        return;
    }
    arr[size] = data;
    heapify_up(size);
    size = size+1;
    return;
}

void heapify_down(int parent){
    if(arr[parent] == -1){
        return;
    }

    int child_l = 2*parent + 1;
    int child_r = 2*parent + 2;

    int child;

    if(child_l>=size && child_r>=size){
        return;
    }
    else if(child_l>=size){
        child = child_r;
    }
    else if(child_r>=size){
        child = child_l;
    }
    else{
        if(arr[child_l]>arr[child_r]){
            child = child_l;
        }
        else{
            child = child_r;
        }
    }

    if(arr[child]>arr[parent]){
        swap(&arr[child], &arr[parent]);
    }
    heapify_down(child);
}

void deletion(){
    int pos = size-1;
    swap(&arr[0], &arr[pos]);
    arr[pos] = -1;
    size = pos;

    heapify_down(0);
}

void display(){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    init();

    insertion(87);
    insertion(90);
    insertion(85);
    insertion(80);
    insertion(86);
    insertion(88);
    insertion(100);

    display();

    deletion();
    display();

    deletion();
    display();

    return 0;

}