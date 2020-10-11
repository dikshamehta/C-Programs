#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;  
};

struct LinkedList{
    struct Node* head; 
};

typedef struct Node NODE;

typedef struct LinkedList LL;


NODE* newNode(int data){
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->next = NULL;
    return node;
}

LL* newLinkedList(){
    LL *l1 = (LL*)malloc(sizeof(LL));
    l1->head = NULL;
    return l1;
}

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

void insert(LL *l, int data){
    NODE *new_node = newNode(data);

    if(l->head == NULL){
        l->head = new_node;   
    }
    //head --> new_node->next --> old_node, this is how things are stored   
    else{
        NODE *temp;
        temp = l->head;
        l->head = new_node;
        new_node->next = temp; 
    }
}

//========================Insertion_at_the_end==============================

void insert_end(LL *l, int data){
    //making new node 
    NODE *new_node = newNode(data);

    //traversing till the end - t == head, t = t.next 
    NODE *t = l->head; 
    if(l->head == NULL){
        l->head = new_node;
        return; 
    }

    while(t->next!=NULL){
        t = t->next;
    }
    t->next = new_node;
}

//=======================Insertion_in_middle==================

void insert_mid(LL *l, int data, int index){
    //creating new node 
    NODE *new_node = newNode(data);

    //if index is negative
    if(index<0){
        printf("please enter valid index\n");
        return;
    } 
    if(index == 0)
    {
        insert(l, data);
        return;
    }

    //insertion at any mid index
    NODE *t = l->head;

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
        insert_end(l, data);
    }
    else{
        NODE *temp = t;
        temp = t->next;
        t->next = new_node;
        new_node->next = temp;
    }
     
}



/* =======================Traversal=========================== */
void traverse(LL *l){
    NODE* t = l->head; 
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

void delete(LL *l){
    if(l->head == NULL){
        printf("it is empty\n");
    }
    else{
        NODE *temp = l->head;
        l->head = l->head->next;
        free(temp);
    }
}

//=======================deletion_at_end===================================
void delete_end(LL *l){
    //if list is empty
    if(l->head == NULL){
        printf("nothing to delete\n");
        return;
    }

    //if list is having only one element
    if(l->head->next == NULL){
        free(l->head);
        l->head = NULL;
        return;
    }

    //if more than one element
    NODE *t = l->head; 
    while(t->next->next!=NULL){
        t = t->next;
    }
    free(t->next);
    t->next = NULL;
 
}

//============================deletion_from_mid===================

void delete_mid(LL *l, int index){
    if(index<0){
        printf("please enter valid index\n");
    }
    else if(index == 0){
        delete(l);
    }

    else{
        NODE *t = l->head;
        int index_ob = 0; 
        for(int i=0; i<index-1; i++){
            t = t->next;
            if(t==NULL || t->next == NULL){
                index_ob = 1;
                break;
            }
        }

        if(index_ob){
            printf("Out of bound\n");
        }
        else{
            NODE *temp;
            temp = t->next->next;
            free(t->next);
            t->next = temp;

        }
        
    }
}



// int main(){
//     LL *l1 = newLinkedList();
//     insert(l1, 3);
//     insert(l1, 4);
//     insert(l1, 8);
//     insert(l1, 5);
//     // insert_end(9);
//     // delete();
//     // delete_end();
//     //insert_mid(0, 8);
//     traverse(l1);
//     delete_mid(l1, 3);
//     traverse(l1);
//     return 0;
// }