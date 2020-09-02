#include<stdio.h>
#define SIZE 14


//this will give these contants(monday . tuesdaye etc) some integer values by deafult or we can assign too 
enum day {
	Monday, //0 
	Tuesday, //1
	Wednesday, //2
	Thrusday, //3
	Friday=100, //100
	Saturday, //since we have given friday 100 explicitly this one will have 101 and sunday will have 102  
	Sunday
};
typedef enum day DAY; 
int main() {
	enum day d1; //enum variable d1
	DAY d2;//enum var d2

	d1 = Monday; //using these as integer constants 
	d2 = Tuesday;

	printf("%d %d %d %d\n", d1, d2, Friday, Saturday);
	return 0;
}
