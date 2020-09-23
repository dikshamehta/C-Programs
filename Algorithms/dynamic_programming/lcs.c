#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
string : aabcdeffg
subsequence : abde, dffg
substring: aab, effg, bcd

so there is difference between subsequence and substring 
*/


int max(int x, int y){
    return x>y?x:y;
}

//recursive method
int lcs(char *s1, char *s2, int l1, int l2){
    if(l1==-1 || l2==-1){
        return 0;
    }

    if(s1[l1]==s2[l2]){
        return 1+lcs(s1, s2, l1-1, l2-1);
    }
    else{
        int ls1 = lcs(s1, s2, l1-1, l2);
        int ls2 = lcs(s1, s2, l1, l2-1);
        return max(ls1, ls2);
    }
}

//here in recursion if we make tree structure still a lot of recursive calls are repeating so dynamic prog should be used

/*
array structure
l1 = 3, l2 = 4
table size = 4*5

0   0   0   0   0
0  -1  -1  -1  -1
0  -1  -1  -1  -1
0  -1  -1  -1  -1

this is the structure that will form after code will run and -1 will be replaced wit
respective values of lcs on that particular coordinate

For eg lcs(1,1) will be stored at table[1][1] 
*/


//dynamic programming 
int lcs_dp(int **table, char *s1, char *s2, int l1, int l2){
    if(l1==0 || l2==0){
        table[l1][l2] = 0;
        return 0; 
    }
    if(s1[l1-1]==s2[l2-1]){
        if(table[l1][l2]==-1){
            table[l1][l2] = 1 + lcs_dp(table ,s1, s2, l1-1, l2-1);
        }
        return table[l1][l2];
    }
    else{
        if(table[l1-1][l2]==-1){
            table[l1-1][l2] = lcs(s1, s2, l1-1, l2);
        }
        else if(table[l1][l2-1]==-1){
            table[l1][l2-1] = lcs(s1, s2, l1, l2-1);
        }
        return max(table[l1-1][l2], table[l1][l2-1]);
    }
}


int main(){
    char s1[] = "aabcdeffgw";
    char s2[] = "aedffgw";    

    int l1 = strlen(s1);
    int l2 = strlen(s2);

    int m = l1+1; //no. of rows 
    int n = l2+1; //no. of columns 

    int **table = (int**)malloc(sizeof(int*)*m);
    for(int i=0; i<m; i++){
        table[i] = (int*)malloc(sizeof(int)*n);
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            table[i][j] = -1;
        }
    }

    //int len = lcs(s1, s2, l1-1, l2-1);

    int len = lcs_dp((int **)table, s1, s2, l1, l2); //(int **) is type casting 
    printf("%d\n", len);
    return 0;
}
    
