#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;  
};

typedef struct Node NODE;

NODE* head = NULL;

/*  
=================Insertion========================
allocate new node
    if head == NULL then : 
        pass its address to head 
    else:
        temp = head
        head = new_node            
        new_node->next = temp  
*/ 
void insert(int data){
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = data;  
    new_node->next = NULL;

    if(head == NULL){
        head = new_node;   
    }
    //head --> new_node->next --> old_node, this is how things are stored   
    else{
        NODE* temp;
        temp = head;
        head = new_node;
        new_node->next = temp; 
    }
}

/* =======================Traversal=========================== */
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

/*======================deletion_from_start===============================*/

void delete(){
    if(head == NULL){
        printf("it is empty\n");
    }
    else{
        NODE *temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    insert(3);
    insert(4);
    insert(8);
    insert(5);
    traverse();
    delete();
    traverse();
    return 0;
}