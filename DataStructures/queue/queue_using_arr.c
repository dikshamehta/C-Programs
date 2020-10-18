#include<stdio.h>

#define N 6

int rear = -1;
int front = -1;

int arr[N];

void enqueue(int data){
    if(rear == -1){
        rear = rear + 1;
        front = front + 1;
        arr[rear] = data;
        return; 
    }

    if(rear == N-1){
        printf("overflow\n");
    }
    else{
        rear = rear+1;
        arr[rear] = data;
    }
}

void traverse(){
    for(int i=front; i<=rear; i++){
        printf(" %d ", arr[i]);
    }
    printf("\n");    

}

void dequeue(){
    if(front == -1 || front>rear){
        printf("empty queue");
    }
    else{
        front = front + 1;
    }
    
}

int main(){
    enqueue(3);
    enqueue(4);
    enqueue(5);

    traverse();

    dequeue();

    traverse();

    enqueue(6);

    traverse();

    return 0;
}