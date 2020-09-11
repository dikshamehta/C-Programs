//evaluation of postfix expressions using stack 

/*
Algorithm:

P = contains postfix expression 

Example:
    s = stack
    Infix Expression : a/b+c*(d+e)

    p = ab/cde+*+
    now in order to evaluate we need to give constant values to variable,
    a = 1, b = 2, c = 3 , d = 4, e = 5

    p = 1,2,/,3,4,5,+,*,+

    step 1: 
    p = 1,2,/,3,4,5,+,*,+,)

    step 2,3,4:
        round 1:---1
        s = 1

        round 2:---2
        s = 1 2

        round 3:---/
        A = 2, B = 1
        B/A => 1/2 = 0
        s = 0

        round 4:---3
        s = 0 3

        round 5:---4
        s = 0 3 4

        round 6:---5
        s = 0 3 4 5 

        round 7:---+
        A = 5, B = 4
        B+A = 4+5 = 9
        s = 0 3 9 

        round 8:---*
        A = 9, B = 3
        B*A = 3*9 = 27
        s = 0 27

        round 9:---+
        A = 27, B = 0
        B+A = 27+0 = 27
        s = 27

        round 10:---)
        exit loop 

    value = top pf stack = 27 
*/

#include<stdio.h>
#include"infix_to_postfix.c"

int compute(int x, int y, char O){
    switch(O)
    {
        case '+':
            return x+y;

        case '-':
            return x-y;

        case '*':
            return x*y;

        case '/':
            return x/y;

        case '^':
            return x^y;

        default: 
            printf("operator is not correct");
            return -1;
    }
}

int evaluate(char *p, int *vals){
    STACK s;

    strcat(p, ")");

    int i = 0;
    while(p[i]!=')'){
        if(isoperand(p[i])){
            push(&s, vals[p[i]]);
        }
        else if(isoperator(p[i])){
            int a = pop(&s);
            int b = pop(&s);

            push(&s, compute(b,a,p[i]));
        }
        i++;
    }
    return pop(&s);
}

int main(){
    //infix expression 
    char q[] = "a/b+c*(d+e)";

    //array to evaluate constant values of variables in expressions
    int vals[256];
    vals['a'] = 1;
    vals['b'] = 2;
    vals['c'] = 3;
    vals['d'] = 4;
    vals['e'] = 5;

    //postfix expression
    char *p = (char*)malloc(sizeof(char)*strlen(q)+1);
    convert(q, p);
    printf("q: %s\n", q);
    printf("p: %s\n", p);

    int value = evaluate(p, vals);

    printf("value: %d\n",value);

    return 0;
}
