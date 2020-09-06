//it has a previous pointer as well 
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node NODE;

NODE *head = NULL; 

//===================insert before========================
// first param is the address of the node before which we have to insert a new node, data is value of new node to be added 
NODE* insert_before(NODE *node, int data){
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = data;  
    new_node->next = NULL;
    new_node->prev = NULL;


    if(node == NULL){
        printf("passed argument is null, therefore modifying head\n");
        head = new_node;
        return head; 
    }

    new_node->prev = node->prev;

    //checking if the node address before which we have to add new node is null or not,
    //if it is null then head should have new_node
    if(node->prev != NULL){
        node->prev->next = new_node;
    }
    else{
        head = new_node;
    }

    new_node->next = node; 
    node->prev = new_node;

    return new_node;

}

//===========================insert after the given node==========================

NODE *insert_after(NODE* node, int data){
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = data;  
    new_node->next = NULL;
    new_node->prev = NULL;

    //check if given node is last node or not 
    if(node->next != NULL){
        //connecting new node to list after node
        new_node->next = node->next;
        node->next->prev = new_node;

        //connecting whole list including new node to given node 
        new_node->prev = node;
        node->next = new_node;
    }

    else{
        node->next = new_node;
        new_node->prev = node;

    }
    return new_node;
}

//=======================delete the node whose address is given======================

void delete(NODE *node){
    if(node == NULL){
        printf("enter valid element");
        return;
    }

    //checking links next to node 
    if(node->next!=NULL){
        node->next->prev = node->prev;
    }//else do nothing

    //checking links previous of node 
    if(node->prev == NULL){
        head = head->next;
    }
    else{
        node->prev->next = node->next;
    }
    free(node);
}


//=======================traverse========================
void traverse(){
    if(head == NULL){
        printf("No element");
        return;
    }
    NODE *t = head; 
    while(t != NULL){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}


int main(){
    
    NODE *new_node = insert_before(head, 4);
    new_node = insert_before(new_node, 3);
    new_node = insert_before(new_node, 1);

    traverse();

    new_node = insert_after(new_node, 8);

    traverse();

    delete(new_node);

    traverse();

    return 0;
}