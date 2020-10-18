#include<stdio.h>

#include"../trees/max_heap.c"

struct PriorityQueue{
    HEAP *h;
};

typedef struct PriorityQueue PQ;

PQ* newPriorityQueue(int maxcap){
    PQ* pq = (PQ*)malloc(sizeof(PQ));
    pq->h = newHeap(maxcap);
    return pq;
}


void enqueue(PQ* pq, int data){
    insertion(pq->h, data);
}

int dequeue(PQ* pq){
    return deletion(pq->h);
}

int peekPQ(PQ* pq){
    return getRoot(pq->h);
}


int main(){

    int maxcap = 15;
    PQ* pq = newPriorityQueue(maxcap); 
    enqueue(pq, 10);
    enqueue(pq, 12);
    enqueue(pq, 1);
    enqueue(pq, 45);
    enqueue(pq, 4);
    enqueue(pq, 100);
    enqueue(pq, 60);
    enqueue(pq, 88);
    


    printf("deleting: %d\n", dequeue(pq));

    printf("deleting: %d\n", dequeue(pq));

    printf("deleting: %d\n", dequeue(pq));

    printf("peek element: %d\n", peekPQ(pq));

    return 0;
}