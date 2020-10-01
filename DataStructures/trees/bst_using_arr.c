#include<stdio.h>
#define SIZE 100

int arr[SIZE];

void init(){
    for(int i=0; i<SIZE; i++){
        arr[i] = -1;
    }
}

void display(){
    for(int i=0; i<SIZE; i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void insert(int data){
    //check if tree is null
    if(arr[0]==-1){
        arr[0] = data;
        return;
    }
    int k = 0;
    while(arr[k]!=-1){
        if(data > arr[k]){
            k = 2*k + 2;
        }
        else if(data < arr[k]){
            k = 2*k + 1;
        }
        else{
            return;
        }
    }
    arr[k] = data;

}

void traversal_inorder(int root){
    if(arr[root] == -1){
        return;
    }

    traversal_inorder(2*root+1);
    printf("%d", arr[root]);
    traversal_inorder(2*root+2);
}

void traversal_preorder(int root){
    if(arr[root] == -1){
        return;
    }

    printf("%d", arr[root]);
    traversal_inorder(2*root+1);
    traversal_inorder(2*root+2);

}

void traversal_postorder(int root){
    if(arr[root] == -1){
        return;
    }

    traversal_inorder(2*root+1);
    traversal_inorder(2*root+2);
    printf("%d", arr[root]);

}

int min_value(int root){
    if(root==-1){
        return -1;
    }
    else if(arr[2*root+1] == -1){
        return arr[root];
    }
    return min_value(2*root+1);
}


int max_value(int root){
    if(root==-1){
        return -1;
    }
    else if(arr[2*root+2] == -1){
        return arr[root];
    }
    return min_value(2*root+2);
}

void deletion(int root, int key){
    //base case 
    if(arr[root]==-1){
        return;
    }

    if(key > arr[root]){
        deletion(2*root+2, key);
    }
    else if(key < arr[root]){
        deletion(2*root+1, key);
    } 
    else{
        //one or no child
        if(arr[2*root+2]==-1 && arr[2*root+1]==-1){
            arr[root] = -1;
        }
        else if(arr[2*root+2]==-1){
            //if right is null, left has child
            int pred = max_value(2*root+1);
            arr[root] = pred;
            deletion(2*root+1, pred);
        }
        else{
            //left is null or 2 children 
            int suc = min_value(2*root+2);
            arr[root] = suc;
            deletion(2*root+2 ,suc);
        }
    }
}

int main(){
    init();
    //print_arr();
    insert(2);
    insert(1);
    insert(4);
    insert(6);
    insert(5);

    //display();

    traversal_inorder(0);
    printf("\n");
    // traversal_postorder(0);
    // printf("\n");
    // traversal_preorder(0);
    // printf("\n");

    deletion(0, 2);
    traversal_inorder(0);
    printf("\n");
}