//check alphabet or not 
#include<stdio.h>
int is_alpha(char n){
	if(n<=65 && n>=90){
		return 1;
	
	}
	else if(n>=97 && n<=122){
		return 1;
	}
	else{
		return 0;
	}


}

int main(){
	int m;
	m = is_alpha('z');
	if(m==1){
		printf("isalpha");
	}
	else{
		printf("not alpha");
	}
	return 0; 
}
