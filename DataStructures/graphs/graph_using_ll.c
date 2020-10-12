//newGraph, addEdge, display

/*
Representation

this is graph of 3 nodes i.e 0,1,2 and 0 is connected with 1 and 2 

|0|->|2||->|1||
|1|->|0||
|2|->|0||
*/

#include<stdio.h>

#include"../linked_list.c"


struct Graph{
    LL *arr;
    int n;
};

typedef struct Graph GRAPH;

GRAPH* newGraph(int n){
    GRAPH* g = (GRAPH*)malloc(sizeof(GRAPH));
    g->n = n;
    g->arr = (LL*)malloc(sizeof(LL)*n);
    return g;
}


void addEdge(GRAPH *g, int v, int u){
    if(v>=g->n || u>=g->n){
        printf("given nodes out of range");
        return;
    }
    insert(&(g->arr[v]), u);
}

void display(GRAPH *g){
    for(int i=0; i<g->n; i++){
        printf("%d: ", i);
        traverse(&(g->arr[i]));
    }
    printf("\n");
}

int main(){
    //no of nodes
    int n = 5;
    GRAPH *g = newGraph(n);
    addEdge(g, 2, 4);
    addEdge(g, 2, 3);
    addEdge(g, 1, 4);
    addEdge(g, 0, 1);
    addEdge(g, 3, 0);
    addEdge(g, 4, 2);
    display(g);
}