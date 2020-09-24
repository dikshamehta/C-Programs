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

// void insert(int data){
//     //creating first node 
//     if(root == NULL){
//         NODE r = (NODE*)malloc(sizeof(NODE));
//         r.data = data;
//         r->left = NULL;
//         r->right = NULL;

//         root = r;
//         return;
//     }

//     NODE *current = root;
//     while(current->right!=NULL || current->left!=NULL){
//         if(data>current.data){
//            current = current->right;
//         }
        
//     }
//}

void insert_recur(BST *tree, NODE *parent, int data){
    //creating a node
    NODE *r = (NODE*)malloc(sizeof(NODE));
    r->data = data;
    r->left = NULL;
    r->right = NULL;
    
    //base case 
    if(parent == NULL){
        tree->root = r;
        return;
    }

    if((parent->data) >= data){
        //left tree
        if(parent->left==NULL){
            parent->left = r;
        }
        else insert_recur(tree, parent->left, data);
    }
    else{
        //right tree
        if(parent->right==NULL){
            parent->right = r;
        }
        else insert_recur(tree, parent->right, data);
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

    insert_recur(&tree, tree.root, 2);
    insert_recur(&tree, tree.root, 3);
    insert_recur(&tree, tree.root, 1);

    traversal_inorder(tree.root);
    return 0;
}