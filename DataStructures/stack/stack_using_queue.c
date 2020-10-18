//implementing stack using two queues

#include<stdio.h>
#include"../queue/queue_using_ll.c"

/*Algorithm
Method 1 : Making push operation more costly
    push():
        Enqueue x to q2
        One by one dequeue everything from q1 and enqueue to q2.
        Swap the names of q1 and q2

        q1 = | |
        q2 = | |

        round1 
        q2 = |3|, q1 = | |
        swap : q1 = |3| and q2 = | |

        round2
        q2 = |4|, q1 = |3|
        q2 = |3,4|
        swap: q1 = |3,4|, q2 = | |

        round3
        q2 = |5|, q1 =|3,4|
        q2 = |3,4,5|
        swap: q1 = |3,4,5|, q2 = | |

        Note here q1 is forming as a stack

        complexity = O(n)

    pop(): 
        Dequeue an item from q1 and return it.

        complexity = O(1)
*/

QUEUE q1;
QUEUE q2;

void init(){
    q1.front = NULL;
    q1.rear = NULL;

    q2.front = NULL;
    q2.rear = NULL; 
}

void swap(){
    QUEUE temp = q1;
    q1 = q2;
    q2 = temp;
}

void push(int data){
    enqueue(&q2, data);
    while(!isempty(&q1)){
        enqueue(&q2, dequeue(&q1));
    }
    swap();  
}

int pop(){
    return dequeue(&q1);
}

void traverse_stack(){
    traverse(&q1);
}

int main(){
    init();

    push(4);
    push(5);
    push(6);
    traverse_stack();
    pop();
    traverse_stack();
    pop();
    traverse_stack();
    pop();
    traverse_stack();
    return 0;
}