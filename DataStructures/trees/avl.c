#include<stdio.h>
#include<stdlib.h>

struct Node{
    int key;
    int h; 
    struct Node *left;
    struct Node *right;
};

//h variable is storing height of individual node, considering that node as root
//so its h = 1 + max(height of lef subtree, height of right subtree)

typedef struct Node NODE;

//inline this function will sbstitute there where ever we call this 
static inline int max(int x, int y){
    return (x>y)?x:y ;
}

int height(NODE *t){
    if(t == NULL){
        return 0;
    }
    return t->h;
}

NODE* newNode(int key){
    NODE *t = (NODE*)malloc(sizeof(NODE));
    t->key = key;
    t->h = 1;
    t->left = NULL;
    t->right = NULL;

    return t;
}

NODE* leftRotation(NODE *t){
    //if t is null
    if(t == NULL){
        return NULL;
    }

    //assuming that right child of "t" in existing 
    NODE *temp = t->right;
    t->right = temp->left;
    temp->left = t;

    //updating heights of t and temp
    t->h = 1 + max(height(t->left), height(t->right));
    temp->h = 1 + max(height(temp->left), height(temp->right));

    return temp;
}

NODE* rightRotation(NODE *t){
    //if t is null
    if(t == NULL){
        return NULL;
    }

    //assuming that left child of "t" in existing
    NODE *temp = t->left;
    t->left = temp->right;
    temp->right = t; 

    //updating heights of t and temp 
    t->h = 1 + max(height(t->left), height(t->right));
    temp->h = 1 + max(height(temp->left), height(temp->right));    

    return temp;
}

int balanceFactor(NODE *root){
    if(root == NULL){
        return 0;
    }
    return height(root->left) - height(root->right);
}

NODE* insert(NODE *root, int key){
    //inserting just like in BST 
    if(root == NULL){
        return newNode(key);
    }
    if(key>root->key){
        root->right = insert(root->right, key);
    }
    else if(key<root->key){
        root->left = insert(root->left, key);
    }
    else{
        return root;
    }

    //updating height 
    root->h = 1+max(height(root->left), height(root->right));

    //now checking balance factor
    int bf = balanceFactor(root);

    if(bf<-1 && key>root->right->key){
        //case: RR
        root = leftRotation(root);
    }
    else if(bf<-1 && key<root->right->key){
        //case: RL
        root->right = rightRotation(root->right);
        root = leftRotation(root);

    }
    else if(bf>1 && key>root->left->key){
        //case: LR
        root->left = leftRotation(root->left);
        root = rightRotation(root);
    }
    else if(bf>1 && key<root->left->key){
        //case: LL
        root = rightRotation(root);
    }
    

    return root; 
}

void inorderTraversal(NODE *root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->key);
    inorderTraversal(root->right);
}

int main(){
    NODE *root = NULL;

    root = insert(root, 12);
    root = insert(root, 90);
    root = insert(root, 8);
    root = insert(root, 20);
    root = insert(root, 13);
    root = insert(root, 15);
    root = insert(root, 19);
    root = insert(root, 62);
    root = insert(root, 70);
    root = insert(root, 45);

    inorderTraversal(root);

    return 0;
}

