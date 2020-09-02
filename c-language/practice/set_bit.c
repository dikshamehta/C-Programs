#Set the bit of a number on a particular position 
#include<stdio.h>
#include <math.h>

int set_bit(int n , int i){
	int m;
	int res;
	//m = pow(2, i); // alternate way 
	//m = 2 << (i-1);, problem : wont work for i = 0
	m = 1 << i; //will work 
	res = n|m;
	return res;
}

int main(){
	int res;
	res = set_bit(9, 2);
	printf("%d", res);
	return 0;

//	5 - 0101
//	3 - 0011
//	Ans - 1101
//	note : -lm is dynamic linking, in case it doesnt happen on its own, refer notes for more info 
}
