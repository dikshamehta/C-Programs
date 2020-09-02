#include<stdio.h>

int main(){
    int arr[10];
    FILE* stream = fopen("stream_test_2", "r");

    fread(arr, sizeof(int), 3, stream);

    printf("%d-%d-%d",arr[0],arr[1], arr[2]); 
 
    fclose(stream);
    
    return 0;
}

