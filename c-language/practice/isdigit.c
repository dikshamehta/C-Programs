//is digit or not 
#include <stdio.h>
int isdigit(char n){
	if(n>='0' && n<='9'){ //take care of quotes
		return 1;
		printf("in");
	}
	else{
		return 0;
	}
}
int main(){
	int m;
	m=isdigit('!');
	if(m==0){
		printf("no. is not a digit");
	}
	else{
		printf("no. is a digit");
	}
	return 0;
}
