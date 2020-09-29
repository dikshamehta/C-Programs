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
    traversal_postorder(0);
    printf("\n");
    traversal_preorder(0);
    printf("\n");
}