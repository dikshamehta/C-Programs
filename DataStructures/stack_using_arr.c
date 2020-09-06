//implementation using array

#include<stdio.h>

#define N 6

int top = -1;
int arr[N];

void push(int data){
    if(top < N){
        top = top + 1;
        arr[top] = data;
    }
    else{
        printf("stack overflow");
    }
}

void traverse(){
    for(int i=0; i<=top; i++){
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

void pop(){
    if(top == -1){
        printf("stack is empty\n");
    }
    else{
        arr[top] = 0;
        top = top - 1; 
    }
}

int main(){
    push(2);
    push(3);
    push(4);

    traverse();

    pop();

    traverse();

    push(5);

    traverse();

    return 0;
}


//taking fixed sized array