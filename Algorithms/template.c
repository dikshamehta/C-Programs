#include<stdio.h>
#define DEBUG 


int main(){

    #ifdef DEBUG
    stdin = fopen("input.txt", "r");
    stdout = fopen("output.txt", "w");
    #endif

    return 0;
}
