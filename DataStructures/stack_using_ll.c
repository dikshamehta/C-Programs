//implementation of stack using linked list
//operation: push, pop. peek 

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next; 
};

typedef struct Node NODE;

NODE* head = NULL;

//this function is same as insert of linked list
void push(int data){
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node -> data = data;
    new_node ->  next = NULL;

    if(head == NULL){
        head = new_node;
    }
    else{
        NODE *temp = head;
        head = new_node;
        new_node->next = temp;
    }

}




void traverse(){
    NODE* t = head; 
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

void pop(){
    if(head == NULL){
        printf("nothing to delete"); 
    }
    else{
        head = head->next;
    }
}

int peek(){
    if(head == NULL){
        printf("underflow");
    }
    else{

        return (head->data);
        
    }
}

int length(){
    NODE* t = head; 
    int count = 0;
    while(t != NULL){
        t = t->next;
        count = count + 1;
    }
    return count;
}
    

int main(){
    push(4);
    push(5);
    push(3);

    traverse();

    pop();

    traverse();

    printf("Top element: %d\n", peek());

    printf("Length: %d\n", length());

    return 0; 
}
