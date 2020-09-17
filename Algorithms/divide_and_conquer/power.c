//implement power fucntion using recursion 
#include<stdio.h>

//time complexity O(n) 
long power_itr(int a,int n){
    long res = 1;
    for(int i=0; i<n; i++){
        res = res * a;
    }
    return res;
}


//this one is also having O(n), but space complexity(input size + stack size(no. of func calls)) is more than iterator
long power(int a, int n){
    if(n == 0){
        return 1;
    }
    int t = power(a, n-1);
    return(t*a);
}

//time complexity O(log n) 
long power_dc(int a, int n){
    if(n == 0){
        return 1;
    }
    if(n%2==0){
        long t = power_dc(a, n/2);
        return t*t;
    }
    else{
        long t = power_dc(a, n/2);
        return t*t*a;
    }
}

int main(){
    int a = 2;
    int n = 5;
    long res = power_dc(a,n);
    printf("%ld\n", res);
}
