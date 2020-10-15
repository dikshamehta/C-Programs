#include<stdio.h>
#include<stdlib.h>

struct Graph{
    int n; //no. of vertices 
    int **matrix;
};

typedef struct Graph GRAPH;

GRAPH* newAMGraph(int n){
    GRAPH *g = (GRAPH*)malloc(sizeof(GRAPH));
    g->n = n;
    g->matrix = (int**) malloc(n*sizeof(int*));

    for(int i=0; i<n; i++){
       g->matrix[i] = (int*)calloc(n, sizeof(int));
    }
    return g;
}

void addAMEdge(GRAPH *g, int u, int v, int w){
    if(u>=g->n || v>=g->n){
        printf("index out of bound");
        return;
    }
    g->matrix[u][v] = w;
}

void addAMEdgeUndirected(GRAPH *g, int u, int v, int w){
    addAMEdge(g, u, v, w);
    addAMEdge(g, v, u, w);
}

int getAMEdge(GRAPH *g, int u, int v){

    if(u>=g->n || v>=g->n){
    printf("index out of bound");
    return -1;
    }

    return g->matrix[u][v];
}

void displayAM(GRAPH *g){
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
//     GRAPH *g = newAMGraph(n);
//     displayAM(g);

//     printf("\n");

//     addAMEdge(g, 2, 4, 4);
//     displayAM(g);

//     int w = getAMEdge(g, 2, 4);
//     printf("\n%d\n", w);

//     return 0;
// }
