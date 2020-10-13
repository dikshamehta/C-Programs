//algorithm for finding prime numbers less than a given number n using sieve of erathosthenes

#include<stdio.h>
#include<math.h>

void sieve(int *prime, int n){
    for(int i=2; i<sqrt(n); i++){
        if(prime[i]==1){
            int j = i*i;
            while(j<n){
                prime[j] = 0;
                j = j + i;
            }
        }
    }
    return;
}

int main(){
    int n = 1000; 
    int prime[n];
    for(int i=2; i<n; i++){
        prime[i] = 1;
    }

    sieve(prime, n);

    for(int i=0; i<n; i++){
        if(prime[i]==1){
            printf("%d ", i);
        }
    }
    printf("\n"); 
}
