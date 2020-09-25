//binary search tree using linked list 

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node NODE;

struct bst{
    NODE *root;
};

typedef struct bst BST; 

void insert(BST *tree, int data){
    //creating a node 
    NODE *r = (NODE*)malloc(sizeof(NODE));
    r->data = data;
    r->left = NULL;
    r->right = NULL;

    //base case 
    if(tree->root == NULL){
        tree->root = r;
        return;
    }

    NODE **current = &(tree->root);

    /*
    *p = value at address that p is storing 

    current = 100

    |100| (address of address of root node)
    |
    |200| (address of root node)

    |200|
    |
    root node

    now this root node is further storing left and right pointers which are storing their addresses further 

    now we want to store the adress of right pointer of root into current 
    */

    while(*current != NULL){
        if(data > (*current)->data){
           current = &((*current)->right);
        }
        else{
            current = &((*current)->left);
        }
    }

    *current = r;    
    return;
}

void insert_recur(NODE **parent, int data){
    //base case 
    if(*parent == NULL){
        //creating a node
        NODE *r = (NODE*)malloc(sizeof(NODE));
        r->data = data;
        r->left = NULL;
        r->right = NULL;

        *parent = r;
    }
    else if(data > (*parent)->data){
        insert_recur(&((*parent)->right), data);
    }
    else{
        insert_recur(&((*parent)->left), data);
    }
}

void traversal_inorder(NODE *parent){
    if(parent == NULL){
        return;
    }

    traversal_inorder(parent->left);
    printf("%d\n", parent->data);
    traversal_inorder(parent->right);
}


int main(){
    BST tree;
    tree.root = NULL;

    insert_recur(&(tree.root), 2);
    insert_recur(&(tree.root), 3);
    insert_recur(&(tree.root), 1);

    // insert(&tree, 2);
    // insert(&tree, 3);
    // insert(&tree, 1);
    // insert(&tree, 4);
 

    traversal_inorder(tree.root); //left root right 
    return 0;
}