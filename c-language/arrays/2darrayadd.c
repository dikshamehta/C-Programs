//add 2d arrays
#include<stdio.h>
#include<stdlib.h>

//this method of local variable declaration was resulting in segmentation fault because of stack memeory usage even after function was removed from the stack, therefore we will use heap memory by implementing dynamaic allocation 
/*int(* add(int (*a)[2], int s1, int (*b)[2]))[2]{
	int c[3][2];
	for(int i=0; i<s1; i++){
		for(int j=0; j<2; j++){
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	return(c);
}*/

int** add_improved(int(*a)[2], int(*b)[2], int s1){
	printf("okkk\n");
	void *ptr1 = malloc(sizeof(int*)*s1);
	int **c = (int**)ptr1;

	for(int i=0; i<s1; i++){
		void* ptr2 = malloc(sizeof(int)*2);
		c[i] = (int*)ptr2; 
	}

	printf("abc\n");

   	for(int i=0; i<s1; i++){
		for(int j=0; j<2; j++){
			c[i][j] = a[i][j] + b[i][j];
	       	}
       	}
	printf("aaa\n");
	return c;
}



//here int(*d)[2] is array pointer which by the way can be written as int d[][2] also both are same refer page 28 of the notes for further difference
void test1(int(*d)[2]){
	printf("%d\n", d);
	printf("%d", **d);
}

int main(){
	//int (*c1)[2]; //here in only declaration we will have to mention proper size c1[][2] will not work
	
	int** c1;

	int d[][2] = {{1,2},{3,4},{5,6}};
	//test1(d);

	int b[][2] = {{1,2},{0,0},{0,0}};

	//c1 = add(d,3,b);
	printf("main %d %d\n", d, *d);
	c1 = add_improved(d,b,3);

	for(int i=0;i<3;++i) {
		for(int j=0;j<2;++j) {
			printf("%d ", c1[i][j]);
		}
		printf("\n");
	}

	return(0);
}

