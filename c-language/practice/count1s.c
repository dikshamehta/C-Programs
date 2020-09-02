//counting number of 1s using bitwise operator 
#include<stdio.h>
int count1s(int n){
        int m=1; //generally called bit mask
        int count = 0;
        while(n!=0){
                if(n & m == 1){ //m will mask all the bits expect LSB, 11001 & 00001 = 00001 or 11000 & 00000
                        count = count + 1;
                }
                n=n>>1;

        }
        printf("%d", count);
}

int main(){
        count1s('A');
}
