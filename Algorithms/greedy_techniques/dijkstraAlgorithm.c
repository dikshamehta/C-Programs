#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#include"../../DataStructures/graphs/graph_using_matrix.c"

#define INF INT_MAX

void dijkstra(GRAPH_AM *g, int *parent, int snode){
    int dist[g->n];
    int visited[g->n];


    //initialize distance with infinity for all other nodes
    for(int i=0; i<g->n; i++){
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[snode] = 0;
    visited[snode] = 1;
    parent[snode] = -1;

    int cnode = snode;

    for(int i=0; i<g->n; i++){
        int mindis = INF;
        int minnode;

        for(int i=0; i<g->n; i++){
            //getting adjacent and unvisited edges of current node, updating their minimum distances
            if(g->matrix[cnode][i] && !visited[i]){
                int newDist = dist[cnode]+getAMEdge(g, cnode, i);
                if(newDist < dist[i]){
                    parent[i] = cnode;
                    dist[i] = newDist;
                }
            }

            //checking the min distance node
            if(dist[i]<mindis && !visited[i]){
                mindis = dist[i];
                minnode = i;
            }
        }

        visited[minnode] = 1;
        cnode = minnode;
    }
}


int main(){
    GRAPH_AM *g = newAMGraph(7);
    int parent[g->n];
    addAMEdgeUndirected(g, 0, 1, 2);
    addAMEdgeUndirected(g, 0, 2, 6);
    addAMEdgeUndirected(g, 1, 3, 5);
    addAMEdgeUndirected(g, 2, 3, 8);
    addAMEdgeUndirected(g, 3, 5, 15);
    addAMEdgeUndirected(g, 3, 4, 10);
    addAMEdgeUndirected(g, 4, 5, 6);
    addAMEdgeUndirected(g, 4, 6, 2);
    addAMEdgeUndirected(g, 5, 6, 6);

    dijkstra(g, parent, 0);

    for(int i=0; i<g->n; i++){
        printf("%d - %d\n", i, parent[i]);
    }

    printf("\n");

}