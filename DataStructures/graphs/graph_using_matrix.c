#include<stdio.h>
#include<stdlib.h>

struct Graph{
    int n; //no. of vertices 
    int **matrix;
};

typedef struct Graph GRAPH;

GRAPH* newGraph(int n){
    GRAPH *g = (GRAPH*)malloc(sizeof(GRAPH));
    g->n = n;
    g->matrix = (int**) malloc(n*sizeof(int*));

    for(int i=0; i<n; i++){
       g->matrix[i] = (int*)calloc(n, sizeof(int));
    }
    return g;
}

void addEdge(GRAPH *g, int u, int v, int w){
    if(u>=g->n || v>=g->n){
        printf("index out of bound");
        return;
    }
    g->matrix[u][v] = w;
}

void addEdgeUndirected(GRAPH *g, int u, int v, int w){
    addEdge(g, u, v, w);
    addEdge(g, v, u, w);
}

int getEdge(GRAPH *g, int u, int v){

    if(u>=g->n || v>=g->n){
    printf("index out of bound");
    return -1;
    }

    return g->matrix[u][v];
}

void display(GRAPH *g){
    printf("Size: %d\n", g->n);
    for(int i=0; i<g->n; i++){
        for(int j=0; j<g->n; j++){
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}

// int main(){
//     int n = 5;
//     GRAPH *g = newGraph(n);
//     display(g);

//     printf("\n");

//     addEdge(g, 2, 4, 4);
//     display(g);

//     int w = getEdge(g, 2, 4);
//     printf("\n%d\n", w);

//     return 0;
// }
