#include<stdio.h>
#include<stdlib.h>
#define MAXCAP 15 //maximum capacity


struct Heap{
    int *arr;
    int size;
};

typedef struct Heap HEAP;

HEAP* newHeap(int maxcap){ 
    HEAP* h = (HEAP*)malloc(sizeof(HEAP));
    h->arr = (int*)malloc(sizeof(int) * maxcap); 

    for(int i=0; i<maxcap; i++){
        h->arr[i] = -1;
    }

    h->size = 0;
    return h;
}

static void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//to arrange newly added element according to heap's property
static void heapify_up(HEAP *h, int pos){
    int child = pos;
    int parent = (child - 1)/2;

    while(h->arr[child] > h->arr[parent]){
        swap(&(h->arr[child]), &(h->arr[parent]));
        child = parent; //update the child as parent 
        parent = (parent - 1)/2; //update the current parent as parent of current parent 
    }
    return;
}

void insertion(HEAP *h, int data){ 
    if(h->size==MAXCAP){
        printf("overflow");
        return;
    }
    h->arr[h->size] = data;
    heapify_up(h, h->size);
    h->size = (h->size)+1;
    return;
}

static void heapify_down(HEAP *h, int parent){
    if(h->arr[parent] == -1){
        return;
    }

    int child_l = 2*parent + 1;
    int child_r = 2*parent + 2;

    int child;

    //if there are no children 
    if(child_l>=h->size && child_r>=h->size){
        return;
    }
    else if(child_l>=h->size){ //only right child exist
        child = child_r;
    }
    else if(child_r>=h->size){ //only left child exist
        child = child_l;
    }
    else{ //when both child exists
        if(h->arr[child_l]>h->arr[child_r]){
            child = child_l;
        }
        else{
            child = child_r;
        }
    }

    //check if largest check is larger than parent or not
    if(h->arr[child]>h->arr[parent]){
        swap(&(h->arr[child]), &(h->arr[parent]));
    }

    //recursion 
    heapify_down(h, child);
}

int deletion(HEAP *h){
    int pos = (h->size)-1;
    int ele = h->arr[0];
    swap(&(h->arr[0]), &(h->arr[pos]));
    h->arr[pos] = -1;
    h->size = pos;

    heapify_down(h, 0);
    return ele;
}

void display(HEAP *h){
    for(int i=0; i<h->size; i++){
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

int getRoot(HEAP* h){
    return h->arr[0];
}

// int main(){

//     int maxcap = 15;
//     HEAP *h = newHeap(maxcap); 

//     insertion(h, 87);
//     insertion(h, 90);
//     insertion(h, 85);
//     insertion(h, 80);
//     insertion(h, 86);
//     insertion(h, 88);
//     insertion(h, 100);

//     display(h);

//     deletion(h);
//     display(h);

//     deletion(h);
//     display(h);

//     return 0;

// }