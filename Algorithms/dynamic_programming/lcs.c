#include<stdio.h>
#include<string.h>
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
int lcs(char *s1, char *s2, int p1, int p2){
    if(p1==-1 || p2==-1){
        return 0;
    }

    if(s1[p1]==s2[p2]){
        return 1+lcs(s1, s2, p1-1, p2-1);
    }
    else{
        int ls1 = lcs(s1, s2, p1-1, p2);
        int ls2 = lcs(s1, s2, p1, p2-1);
        return max(ls1, ls2);
    }
}


int main(){
    char s1[] = "aabcdeffgw";
    char s2[] = "aedffgw";    

    int l1 = strlen(s1);
    int l2 = strlen(s2);

    int len = lcs(s1, s2, l1-1, l2-1);

    printf("%d\n", len);
    return 0;
}
    
