//try1: a naive way to check the max length of elements within string array, see other one in try 2 and usually follow that one only with **

#include<stdio.h>
int strarr(char(*str)[5],int c ){
	int index = 0;
	int max = 0; 
	for(int j=0; j<c; j++){
		int i = 0;
	        int count = 0;
		while(str[j][i]!='\0'){
			count=count+1;
			i++;
		}
		if(count>max){
			max = count;
			index = j;
		}

	}
	return index;
}

int main(){
	int index;
	int c = 3;
	char str[][5] = {{'a', 'b','a', '\0'},{'c','d','e', '\0'},{'f', '\0'}};
	index=strarr(str, c);
	printf("%d", index);
	return 0;

}
