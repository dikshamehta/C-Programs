//implement queue using 2 stack

/*Algorithm
Method 1 : Making enqueue operation more costly
    enqueue():
        While stack1 is not empty, push everything from stack1 to stack2.
        Push x to stack1 (assuming size of stacks is unlimited).
        Push everything back to stack1.

        s1 = | |
        s2 = | |

        round 1
        s1 = |3|, s2 = | |

        round 2
        s2 = |3|
        s1 = |4|
        s1 = |4,3|, s2 = | |

        round 3
        s2 = |3,4|
        s1 = |5|
        s1 = |5,4,3|, s2 = | |

        Note here s1 is forming as a queue
        complexity = O(n)

    dequeue():
        If stack1 is empty then error - situation of underflow
        Pop an item from stack1 and return it - simply dequeuing queue

        complexity = O(1)
*/

#include<stdio.h>
#include"../stack/stack_using_ll.c"  //importing other stack made in other file, plus it is local so " "

STACK s1;
STACK s2;

void init(){
    s1.top = NULL;
    s2.top = NULL;
}

void enqueue(int data){
    while(!isempty(&s1)){
        push(&s2, pop(&s1));
    }
    push(&s1, data);

    while(!isempty(&s2)){
        push(&s1, pop(&s2));
    }
}

int dequeue(){
    if(isempty(&s1)){
        printf("underflow");
        return -1;
    }
    return pop(&s1);
}

void traverse_queue(){
    traverse(&s1);
}
    

int main(){
    init();
    enqueue(5);
    enqueue(6);
    enqueue(4);
    enqueue(3);
    traverse_queue();
    dequeue();
    dequeue();
    traverse_queue();
    enqueue(9);
    traverse_queue();
    return 0;
}