#include<stdio.h>

int main(){
    int arr[3] = {1,2,3};
    FILE* stream = fopen("stream_test_2", "w");

    fwrite(arr, sizeof(int), 3, stream); 

    fclose(stream);
    
    return 0;
}