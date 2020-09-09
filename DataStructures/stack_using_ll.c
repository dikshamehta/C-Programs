//implementation of stack using linked list
//operation: push, pop. peek 

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next; 
};

typedef struct Node NODE;

struct stack{
    NODE *top;
};

typedef struct stack STACK;

//NODE* top = NULL;

//this function is same as insert of linked list
void push(STACK *s, int data){
    NODE **top = &(s->top); 
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node -> data = data;
    new_node ->  next = NULL;

    if(*top == NULL){
        *top = new_node;
    }
    else{
        NODE *temp = *top;
        *top = new_node;
        new_node->next = temp;
    }
}




void traverse(STACK *s){
    NODE **top = &(s->top);
    NODE* t = *top; 
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

int pop(STACK *s){
    NODE **top = &(s->top);
    if(*top == NULL){
        printf("nothing to delete");
        return -1; 
    }
    else{
        int val = (*top)->data;
        NODE *temp = *top;
        *top = (*top)->next;
        free(temp);
        return val;        
    }

}

int peek(STACK *s){
    NODE **top = &(s->top);
    if(*top == NULL){
        printf("underflow");
        return -1;
    }
    else{

        return ((*top)->data);
        
    }
}

int length(STACK *s){
    NODE **top = &(s->top);
    NODE* t = *top; 
    int count = 0;
    while(t != NULL){
        t = t->next;
        count = count + 1;
    }
    return count;
}

int isempty(STACK *s){
    NODE **top = &(s->top);
    return (*top == NULL);
}
    

// int main(){
//     STACK s;
//     s.top = NULL;
//     push(&s,4);
//     push(&s,5);
//     push(&s,3);

//     traverse(&s);

//     pop(&s);

//     traverse(&s);

//     printf("Top element: %d\n", peek(&s));

//     printf("Length: %d\n", length(&s));

//     return 0; 
// }
