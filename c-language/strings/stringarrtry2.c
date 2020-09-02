//check the max length of elements within string array 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max_len_element(char** strarr, int r){
	int index = 0;
	int l;
	int max = 0;
	for(int i=0; i<r; i++){
		l = strlen(strarr[i]);
		if(l>max){
			max = l;
			index = i;
		}
	}
	return index;
}

char** alloc(int r){
	char **strarr = (char**)(malloc(sizeof(char*)*r));
	return strarr;
}

// [*	 	 *	         *]
//  |    	 |    		 |
// [string1]  [strring1]    [strrring1]

int main(){
	int index;
	int r = 3;
	int c = 5;
	char** strarr;
	strarr = alloc(r);
	strarr[0] = "string1"; //these strings will decay from arr to pointer 
        strarr[1] = "strring1";
	strarr[2] = "sting1";
	index = max_len_element(strarr, r);
	printf("%d", index);	
	return 0;
}
