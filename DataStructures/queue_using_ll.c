#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node NODE;

//making structure of front and rear
struct Queue{
    NODE *front;
    NODE *rear;
};

typedef struct Queue QUEUE;

// NODE *front = NULL;
// NODE *rear = NULL;


void enqueue(QUEUE *q, int data){
    //here, q = is a pointer to a variable of QUEUE type, 
    //i.e. QUEUE structure's address is passed and through that we will acces front and rear
    
    //&(q->front) this means address of front variable store inside queue and similarly with rear 
    //also here we are taking **front as the value of front pointer of struct can change in this function
    NODE **front = &(q->front);
    NODE **rear = &(q->rear);

    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node -> data = data;
    new_node -> next = NULL;
    new_node -> prev = NULL;

    if(*rear == NULL){
        *rear = new_node;
        *front = new_node;
    }
    else{
        NODE *temp = *rear;
        *rear = new_node;
        new_node->next = temp;
        temp->prev = new_node;
    }

}

int dequeue(QUEUE *q){
    NODE **front = &(q->front);
    NODE **rear = &(q->rear);

    if(*rear == NULL){
        printf("empty queue");
        return -1;
    }
    else{
        NODE *temp = *front;
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

void traverse(QUEUE *q){
    NODE **rear = &(q->rear);
    if(*rear == NULL){
        printf("No element\n");
        return;
    }
    NODE *t = *rear; 
    while(t != NULL){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int isempty(QUEUE *q){
    return (q->rear == NULL);
}

// int main(){
//     QUEUE q1;
//     q1.front = NULL;
//     q1.rear = NULL; 
//     enqueue(&q1, 4);
//     enqueue(&q1, 3);
//     enqueue(&q1, 5);

//     traverse(&q1);

//     dequeue(&q1);
//     dequeue(&q1);
//     dequeue(&q1);

//     traverse(&q1);

//     enqueue(&q1, 6);

//     traverse(&q1);

//     return 0; 
// }