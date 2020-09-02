#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE* stream = fopen("stream_test_1.txt", "r");
    size_t n = 10; //size_t is typedef for unsigned long

    char* str = (char*)malloc(sizeof(char)*n); //a pointer to the char buffer, so **lineptr mai we will give address to buffer (&str)

    getline(&str, &n, stream);
    printf("%s\n %ld\n", str, n);


    //fgets - difference in these two is of null char 

    fgets(&str, n, stream);
    printf("%s\n", str);
    return 0;
}