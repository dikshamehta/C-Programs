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


//left root right 
void traversal_inorder(NODE *parent){
    if(parent == NULL){
        return;
    }
    traversal_inorder(parent->left);
    printf("%d\n", parent->data);
    traversal_inorder(parent->right);
}

//root left right 
void traversal_preorder(NODE *parent){
    if(parent == NULL){
        return;
    }
    printf("%d\n", parent->data);
    traversal_preorder(parent->left);
    traversal_preorder(parent->right);
}

//left right root
void traversal_postorder(NODE *parent){
    if(parent == NULL){
        return;
    }
    traversal_preorder(parent->left);
    traversal_preorder(parent->right);
    printf("%d\n", parent->data);
}

NODE* search_recur(NODE *parent, int data){
    if(parent == NULL){
        return NULL;
    }

    if(data == parent->data){
        return parent;
    }
    else if(data > parent->data){
        return search_recur(parent->right, data);
    }
    else{
        return search_recur(parent->left, data);
    }
}

NODE* search_itr(NODE *parent ,int data){

    while(parent != NULL){
        if(data == parent->data){
            break;
        }
        else if(data > parent->data){
            parent = parent->right;
        }
        else{
            parent = parent->left;
        }    
    }

    return parent;
}

NODE* minval_node(NODE *root, int key){
    //if root passed is null 
    if(root == NULL){
        return NULL;
    }
    //base case, we stop when we reach minimum in tree
    else if(root->left == NULL){
        return root;
    }
    return minval_node(root->left, key);
}

NODE* delete_recur(NODE *root, int key){
    if(root == NULL){
        return root;
    }

    //case 1: when key is greater than root's data
    if(key > root->data){
        root->right = delete_recur(root->right, key);
    }

    //case 2: when key is less than root's data
    else if(key < root->data){
        root->left = delete_recur(root->left, key);
    }

    //if key is equal to root's data
    else{
        //for one or no child of root node which is equal to key
        if(root->right == NULL){
            NODE *temp = root->left;
            free(root); //delete root
            return temp;
        }
        else{
            NODE *temp = root->right;
            free(root); 
            return temp;
        }

        //if root node to be deleted is having 2 children
        NODE* min = minval_node(root->right, key);
        root->data = min->data;
        //delete min value from the original place 
        root->right = delete_recur(root->right, min->data);
    }
    return root;
}

void delete(BST *tree, int key){
    tree->root = delete_recur(tree->root, key);
}


int main(){
    BST tree;
    tree.root = NULL;

    insert_recur(&(tree.root), 2);
    insert_recur(&(tree.root), 3);
    insert_recur(&(tree.root), 1);
    insert_recur(&(tree.root), 4);
    insert_recur(&(tree.root), 5);
    insert_recur(&(tree.root), 6);

    // insert(&tree, 2);
    // insert(&tree, 3);
    // insert(&tree, 1);
    // insert(&tree, 4);
 

    // traversal_inorder(tree.root); //left root right 

    // traversal_preorder(tree.root); //root left right

    // traversal_postorder(tree.root); //left right root 

    ////search

    // NODE *ele = search_recur(tree.root, 5);
    // printf("%d\n", ele->data);
    // if(ele == NULL){
    //     printf("Not found\n");
    // }
    // else{
    //     printf("element found\n");
    // }

    // printf("%d\n",search_itr(tree.root, 5));

    delete(&tree, 4);

    traversal_inorder(tree.root);

    return 0;
}