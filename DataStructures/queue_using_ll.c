#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node NODE;

NODE *front = NULL;
NODE *rear = NULL;

void enqueue(int data){
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node -> data = data;
    new_node -> next = NULL;
    new_node -> prev = NULL;

    if(rear == NULL){
        rear = new_node;
        front = new_node;
    }
    else{
        NODE *temp = rear;
        rear = new_node;
        new_node->next = temp;
        temp->prev = new_node;
    }

}

int dequeue(){
    if(rear == NULL){
        printf("empty queue");
        return -1;
    }

    else{
        NODE *temp = front;
        int data = front->data; 
        front->prev->next = NULL;
        front = front->prev;
        free(temp);
        return data;
    }

}

void traverse(){
    if(rear == NULL){
        printf("No element");
        return;
    }
    NODE *t = rear; 
    while(t != NULL){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main(){

    enqueue(4);
    enqueue(3);
    enqueue(5);

    traverse();

    int data = dequeue();

    printf("deleted %d \n", data);

    traverse();

    enqueue(6);

    traverse();

    return 0; 
}