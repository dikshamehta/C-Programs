#include<stdio.h>
#include<stdlib.h>

struct NodeQ{
    int data;
    struct NodeQ *next;
    struct NodeQ *prev;
};

typedef struct NodeQ NodeQ;

//making structure of front and rear
struct Queue{
    NodeQ *front;
    NodeQ *rear;
};

typedef struct Queue QUEUE;

// NodeQ *front = NULL;
// NodeQ *rear = NULL;


void enqueue(QUEUE *q, int data){
    //here, q = is a pointer to a variable of QUEUE type, 
    //i.e. QUEUE structure's address is passed and through that we will acces front and rear
    
    //&(q->front) this means address of front variable store inside queue and similarly with rear 
    //also here we are taking **front as the value of front pointer of struct can change in this function
    NodeQ **front = &(q->front);
    NodeQ **rear = &(q->rear);

    NodeQ *new_NodeQ = (NodeQ*)malloc(sizeof(NodeQ));
    new_NodeQ -> data = data;
    new_NodeQ -> next = NULL;
    new_NodeQ -> prev = NULL;

    if(*rear == NULL){
        *rear = new_NodeQ;
        *front = new_NodeQ;
    }
    else{
        NodeQ *temp = *rear;
        *rear = new_NodeQ;
        new_NodeQ->next = temp;
        temp->prev = new_NodeQ;
    }

}

int dequeue(QUEUE *q){
    NodeQ **front = &(q->front);
    NodeQ **rear = &(q->rear);

    if(*rear == NULL){
        printf("empty queue");
        return -1;
    }
    else{
        NodeQ *temp = *front;
        int data = (*front)->data;
        if(*rear == *front){
            //only one element in the queue 
            *rear = NULL;
            *front = NULL; 
        } 
        else{
            (*front)->prev->next = NULL;
            *front = (*front)->prev;
        }
        free(temp);
        return data;
    }
}

void traverseQ(QUEUE *q){
    NodeQ **rear = &(q->rear);
    if(*rear == NULL){
        printf("No element\n");
        return;
    }
    NodeQ *t = *rear; 
    while(t != NULL){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int isemptyQ(QUEUE *q){
    return (q->rear == NULL);
}

// int main(){
//     QUEUE q1;
//     q1.front = NULL;
//     q1.rear = NULL; 
//     enqueue(&q1, 4);
//     enqueue(&q1, 3);
//     enqueue(&q1, 5);

//     traverseQ(&q1);

//     dequeue(&q1);
//     dequeue(&q1);
//     dequeue(&q1);

//     traverseQ(&q1);

//     enqueue(&q1, 6);

//     traverseQ(&q1);

//     return 0; 
// }