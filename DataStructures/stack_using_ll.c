//implementation of stack using linked list
//operation: push, pop. peek 

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next; 
};

typedef struct Node NODE;

// NODE* head = NULL;

//this function is same as insert of linked list
void push(NODE **head, int data){
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node -> data = data;
    new_node ->  next = NULL;

    if(*head == NULL){
        *head = new_node;
    }
    else{
        NODE *temp = *head;
        *head = new_node;
        new_node->next = temp;
    }
}




void traverse(NODE **head){
    NODE* t = *head; 
    if(t == NULL){
        printf("it is empty\n");
    }
    else{
        while(t != NULL){
            printf("%d ", t->data);
            t = t->next;
        }
        printf("\n");
    }
}

int pop(NODE **head){
    if(*head == NULL){
        printf("nothing to delete");
        return -1; 
    }
    else{
        int val = (*head)->data;
        NODE *temp = *head;
        *head = (*head)->next;
        free(temp);
        return val;        
    }

}

int peek(NODE **head){
    if(*head == NULL){
        printf("underflow");
        return -1;
    }
    else{

        return ((*head)->data);
        
    }
}

int length(NODE **head){
    NODE* t = *head; 
    int count = 0;
    while(t != NULL){
        t = t->next;
        count = count + 1;
    }
    return count;
}

int isempty(NODE **head){
    return (*head == NULL);
}
    

// int main(){
//     NODE *head = NULL;
//     push(&head,4);
//     push(&head,5);
//     push(&head,3);

//     traverse(&head);

//     pop(&head);

//     traverse(&head);

//     printf("Top element: %d\n", peek(&head));

//     printf("Length: %d\n", length(&head));

//     return 0; 
// }
