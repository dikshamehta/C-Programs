//application of stack
/*
Algorithm from notes
Example:

    Infix Expression : a/b+c*(d+e)
    SOL: ab/cde+*+

    Postflix Evaluation :
        s = (
        q = a/b+c*(d+e))

        step 1 : a
            p = a
            s = (

        step 2 : /
            p = a
            s = /(

        step 3 : b
            p = ab 
            s = /(

        step 4 : +
            p = ab/
            s = +(

        step 5 : c
            p = ab/c
            s = +(

        step 6 : *
            p = ab/c
            s = *+(

        step 7 : (
            p = ab/c
            s = (*+(
            
        step 8 : d
            p = ab/cd
            s = (*+(

        step 9 : +
            p = ab/cd
            s = +(*+(

        step 10 : e
            p = ab/cde
            s = +(*+(

        step 11 : )
            p = ab/cde+
            s = *+(

        step 12 : )
            p = ab/cde+*+
            s = 

    we have reached the solution 
*/

#include<stdio.h>
#include"stack_using_ll.c"
#include<string.h>

#define SIZE 10

int isoperator(char n){
    if(n=='^' || n=='*' || n=='/' || n=='+' || n=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

int compPrecedence(char c1, char c2) {
    char table[256];
    table['^'] = 5;
    table['*'] = 4;
    table['/'] = 4;
    table['+'] = 3;
    table['-'] = 3;

    return table[c1] - table[c2];
}

int isoperand(char n){
    if(!isoperator(n) && n!='(' && n!=')'){
        return 1;
    }
    else{
        return 0;
    }
}

//convert infix to postfix
void convert(const char *q, char *p){
    STACK s; 
    s.top = NULL;
    push(&s,'(');
    char t[strlen(q)+1]; //+1 because strlen does not consider null character
    strcpy(t, q);

    strcat(t, ")");

    int i = 0;

    while(!(isempty(&s))){
        if(isoperand(t[i])){
            strncat(p, &t[i], 1);
        }
        else if(t[i] == '('){
            push(&s, t[i]);
        }
        else if(isoperator(t[i])){
            while(isoperator(peek(&s)) && compPrecedence(peek(&s), t[i])>=0){
                char top = pop(&s);
                strncat(p, &top, 1);
            }
            push(&s, t[i]);
        }
        else{
            while(peek(&s)!='('){
                char top = pop(&s);
                strncat(p, &top, 1);
            }
            pop(&s);//popping '('
        }
        i++;
    }
}

int main(){
    char q[] = "a+(b*c-(d/e^f)*g)*h";
    char *p = (char*)malloc(sizeof(char)*strlen(q)+1);
    convert(q, p);
    printf("q: %s\n", q);
    printf("p: %s\n", p);
    return 0;
}
    
