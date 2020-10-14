#include<stdio.h>
#include<string.h>
#include"graph_using_matrix.c"
#include"../stack_using_ll.c"
#include"../queue_using_ll.c"


void dfsTraversal(GRAPH *g, int start_node, int n){
    STACK s;
    s.top = NULL;
    int visited[n];
    memset(visited, 0, n*sizeof(int));
    visited[start_node] = 1;
    push(&s, start_node);
    printf("%d ", start_node);
    
    while(!isempty(&s)){
        int top = peek(&s);
        int adj = -1;
        for(int i=0; i<g->n; i++){
            if(g->matrix[top][i] && !visited[i]){
                visited[i] = 1;
                adj = i;
                printf("%d ", adj);
                break;
            }
        }
        
        if(adj != -1){
            push(&s, adj);  
        }
        else{
            pop(&s);
        }
    }
    printf("\n");
}

void bfsTraversal(GRAPH *g, int start_node, int n){
    QUEUE q;
    q.front = NULL;
    q.rear = NULL; 

    int visited[n];
    memset(visited, 0, n*sizeof(int));
    visited[start_node] = 1;
    enqueue(&q, start_node);
    printf("%d ", start_node); 

    while(!isemptyQ(&q)){
        int rear = q.rear->data; 
        for(int i=0; i<g->n; i++){
            if(g->matrix[rear][i] && !visited[i]){
                visited[i] = 1;
                printf("%d ", i);
                enqueue(&q, i);
            }
        }
        dequeue(&q);
    }
    printf("\n");
}

int main(){
    int n = 8;
    GRAPH *g = newGraph(n);

    //creation of graph
    addEdgeUndirected(g, 1, 2, 1);
    addEdgeUndirected(g, 1, 5, 1);
    addEdgeUndirected(g, 1, 4, 1);
    addEdgeUndirected(g, 2, 5, 1);
    addEdgeUndirected(g, 2, 3, 1);
    addEdgeUndirected(g, 3, 5, 1);
    addEdgeUndirected(g, 3, 6, 1);
    addEdgeUndirected(g, 3, 7, 1);
    addEdgeUndirected(g, 4, 5, 1);
    addEdgeUndirected(g, 5, 6, 1);
    addEdgeUndirected(g, 6, 7, 1);

    //display(g);

    //dfsTraversal(g, 1, n);

    bfsTraversal(g, 1, n);

}

