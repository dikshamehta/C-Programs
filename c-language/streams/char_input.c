#include<stdio.h>

int main(){
    FILE* stream = fopen("stream_test_1.txt", "r");
    int c = fgetc(stream);
    printf("%d %c", c, c);

    int d = getc(stream);
    printf("%c\n", d);

    int e = getchar();
    printf("%c", e);

    fclose(stream);

    return 0; 
}