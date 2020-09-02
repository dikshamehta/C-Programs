//how is main actually declared 
#include<stdio.h>

//main(int argc, char argv[])
//argc - argument count
//argv - argument values
int main(int argc, char **argv) {
	printf("%d\n", argc);

	for(int i=0;i<argc;++i) {
		printf("%s\n", argv[i]);
	}
	return 0;

}
