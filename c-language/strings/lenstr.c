//write a function to find the len of a string 
#include<stdio.h>

int len(char *str){
	int count = 0;	
	while(str[count]!='\0'){
		count = count + 1;
	}
	return count;
}

int main(){
	int c;
	char str[] = "Tony";
	c = len(str);
	printf("%d", c);
	return 0;
}
