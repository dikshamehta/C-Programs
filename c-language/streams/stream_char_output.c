#include<stdio.h>

int main() {
	FILE* stream = fopen("stream_test_1.txt","w"); //open a stream
	//fputc
	fputc('c', stream);
	fputc('b', stream);

	putc('d', stream);

	//by default stream is stdout for putchar
	putchar('e'); // output on the terminal
	putchar('\n'); // 
	fclose(stream); //fclose(
	return 0;
}
