#include<stdio.h>

int main() {
    FILE* stream = fopen("stream_test_1.txt","w"); //open a stream

    fputs("hello", stream); // it will not put a new line character at the end

    puts("hello"); // it will put a new line character
    fclose(stream);
    return 0;
}