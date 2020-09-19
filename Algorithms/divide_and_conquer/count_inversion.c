#include<stdio.h>

int count_cross(int *arr, int l, int mid, int r){
    int count = 0;
    int p1 = l;
    int p2 = mid+1;
    int arr2[r-l+1];
    
    int i = 0;

    while(p1<=mid && p2<=r){
        if(arr[p1]<=arr[p2]){
            arr2[i] = arr[p1];
            p1++;
        }
        else{
            arr2[i] = arr[p2];
            p2++;
            count++;
        }
        i++;
    }

    //adding rest of the elements for sorting
    if(p1<mid+1){
        while(p1<mid+1){
            arr2[i] = arr[p1];
            p1++;
            i++;
            //inversion will occur in case first part has some remaining elements
            count = count+(r-(mid+1)+1);
        }    
    }
    else if(p2<r+1){
        while(p2<r+1){
            arr2[i] = arr[p2];
            p2++;
            i++;
        }
    }

    //copying whole array back to arr from arr2
    for(int i=l; i<=r; i++){
        arr[i] = arr2[i-l];
    }
    return count;
}

int inversion(int *arr, int l, int r){
    if(l>=r){
        return 0;
    }

    int mid = (l+r)/2;
    int c1 = inversion(arr, l, mid);
    int c2 = inversion(arr, mid+1, r);
    int c3 = count_cross(arr, l, mid, r);
    return (c1+c2+c3);
}

void display(int *arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(){
    //int n = 7;
    // int arr[7] = {4,3,7,1,2,5,8};
    // inversion(arr, 0, n-1);

    // int a[] = {5,10,15,20,25,13,18,20,21};
    // int count = count_cross(a, 0, 4, 8);
    // printf("%d\n", count);
    // display(a, 9);

    int a2[] = {70,20,50,15,65,85,3,2};
    int count = inversion(a2, 0, 7);
    printf("%d\n", count);
    display(a2, 8);

    
    return 0;
}
