#include<stdio.h>
#define DEBUG 

void display(int *arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int *arr, int n){
    int arr2[n];
    for(int i=0; i<n; i++){
        if(i==0){
            arr2[i] = arr[i];
        }
        else{
            for(int j=i-1; j>=0; j--){
                if(arr[i]>arr2[j]){
                    arr2[j+1] = arr[i];
                    break;
                }
                else{
                    arr2[j+1] = arr2[j];
                }
                if(j==0){
                    arr2[j] = arr[i];
                }
            }
        }  
    }
    for(int i=0; i<n; i++){
        arr[i] = arr2[i];
    }
}

//optimized version with less space used
void insertion_sort_v2(int *arr, int n){
    for(int i=1; i<n; i++){
        int current = arr[i];
        for(int j=i-1; j>=0; j--){
            if(current>arr[j]){
                break;
            }
            else{
                arr[j+1] = arr[j];
            }
            if(j==0){
                arr[j] = current;
            }
        } 
    }
}

//version 3
void insertion_sort_v3(int *arr, int n){
    for(int i=1; i<n; i++){
        int current = arr[i];
        int j = i-1;
        //shifting 
        while(j>=0 && arr[j]>current){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current; 
    }
}

int main(){
    
    #ifdef DEBUG
    stdin = fopen("input.txt", "r");
    stdout = fopen("output.txt", "w");
    #endif

    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    // insertion_sort(arr,n);
    insertion_sort_v3(arr,n);
    display(arr, n);
    return 0;
}
