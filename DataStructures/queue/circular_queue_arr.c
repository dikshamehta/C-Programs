//circular queue using array 

#include<stdio.h>

#define N 6

int arr[N];
int rear = -1;
int front = -1;

void enqueue(int data){
    if(rear == -1){
        rear = rear + 1;
        front = front + 1;
        arr[rear] = data;
        return; 
    }
    if((rear+1) % N == front){
            printf("overflow\n");
    }
    else{
        rear = (rear + 1) % N;
        arr[rear] = data;
    }
}


int dequeue(){
    if(front == -1){
        printf("underflow\n");
        return -1;
    }
    int val = arr[front];
    arr[front] = 0; //to view content of queue while debugging 
    if(rear == front){
        rear = front = -1; 
    }
    else{
        front = (front+1) % N;
    }
    return val;
}


void traverse(){
    for(int i=0; i<=N-1; i++){
        printf(" %d ", arr[i]);
    }
    printf("\n");    
}


int main(){
    enqueue(3);
    traverse();
    enqueue(4);
    traverse();
    enqueue(5);
    traverse();
    enqueue(6);
    traverse();
    enqueue(7);
    traverse();
    enqueue(8);
    traverse();
    enqueue(9);
    dequeue();
    traverse();
    dequeue();
    traverse();
    dequeue();
    traverse();
    dequeue();
    traverse();
    dequeue();
    traverse();
    dequeue();
    traverse();
    dequeue();
    traverse();
    enqueue(1);
    traverse();
    
    return 0; 
}