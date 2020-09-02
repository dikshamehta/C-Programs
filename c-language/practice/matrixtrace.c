//function to print the trace of the matrix , i.e principal  diagonal elements are added i.e first wala diagonal 
#include<stdio.h>
#include<stdlib.h>

int matrixtrace(int **arr, int r, int c){
	int sum = 0;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(i==j){
				sum = sum+arr[i][j];
			}
		
		}
	}
	return sum;
}
//=================== dynamic =================================
// 100
// [*(200)  *  *  *]  -- arr[i][j]  == *(*(arr+i) + j) ; arr[0][0] == *(*(100)) == *(200) == 1
//  |
// [1] 200
// [1] 204
// [1]

//================= static =====================================
// arr[][3] = {......} --- arr will be array pointer to the first element
// 100 104 108..................
// [1,  1,  1, 2, 2, 2, 1, 1, 1]
// arr - will decay to array pointer -- int (*)[3]
//arr - value = 100 - when casted to int** -- arr[0][0] == *(*(100)) == *(1) == segmenation fault  

int** allocate_2darray(int r, int c){
	int **arr = (int**)malloc(sizeof(int*)*r);
        for(int i = 0 ; i<r; i++){
		arr[i] = (int*)malloc(sizeof(int)*c);
	}
	return arr;

}

int main(){
	int r,c;
	r = c = 3;
	int** arr = allocate_2darray(r, c);
	for(int i = 0 ; i < r; i++){
		for(int j = 0; j < c; j++){
			arr[i][j] = 1;
		}
	}
	int s = matrixtrace(arr, r, c);
	printf("%d\n", s);
	return 0;

}
