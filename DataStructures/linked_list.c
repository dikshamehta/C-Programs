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

//========================Insertion_at_the_end==============================

void insert_end(int data){
    //making new node 
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = data;
    new_node->next = NULL;

    //traversing till the end - t == head, t = t.next 
    NODE* t = head; 
    if(head == NULL){
        head = new_node;
        return; 
    }

    while(t->next!=NULL){
        t = t->next;
    }
    t->next = new_node;
}

//=======================Insertion_in_middle==================

void insert_mid(int data, int index){
    //creating new node 
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = data;
    new_node->next = NULL;

    //if index is negative
    if(index<0){
        printf("please enter valid index\n");
        return;
    } 
    if(index == 0)
    {
        insert(data);
        return;
    }

    //insertion at any mid index
    NODE *t = head;

    int end_reached = 0;

    for(int i=0; i<index-1; i++){
        t = t->next;
        if(t == NULL){
            end_reached = 1;
            break;
        }
    } 

    if(end_reached){
        printf("adding in the end because u r dumb\n");
        insert_end(data);
    }
    else{
        NODE *temp = t;
        temp = t->next;
        t->next = new_node;
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

//=======================deletion_at_end===================================
void delete_end(){
    //if list is empty
    if(head == NULL){
        printf("nothing to delete\n");
        return;
    }

    //if list is having only one element
    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }

    //if more than one element
    NODE *t = head; 
    while(t->next->next!=NULL){
        t = t->next;
    }
    free(t->next);
    t->next = NULL;
 
}

//=================================deletion_from_mid===================

void delete_mid(int index){
    if(index<0){
        printf("please enter valid index\n");
    }
    else if(index == 0){
        delete();
    }

    else{
        NODE *t = head;
        int index_ob = 0; 
        for(int i=0; i<index-1; i++){
            t = t->next;
            if(t==NULL){
                index_ob = 1;
                break;
            }
        }
        if(index_ob){
            printf("Out of bound\n");
        }
        else{
            if(t->next == NULL){
                delete_end();
            }
            else{
                NODE *temp;
                temp = t->next->next;
                free(t->next);
                t->next = temp;

            }
        }
    }
}

int main(){
    insert(3);
    insert(4);
    insert(8);
    insert(5);
    // insert_end(9);
    // delete();
    // delete_end();
    //insert_mid(0, 8);
    traverse();
    delete_mid(4);
    traverse();
    return 0;
}