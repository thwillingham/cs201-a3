#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "heap.h"
#include "node.h"
#include "linkedList.h"
#include "stack.h"
#include "ds.h"


graph *newGraph(node **vertices, int numVerts, node **edges, int numEdges) {
    graph *g = (graph *) malloc(sizeof(graph));
    if (g==0) { fprintf(stderr,"out of memory"); exit(-1); }
    g->numVerts = numVerts;
    g->numEdges = numEdges;

    g->vertices = vertices;
    g->edges = edges;
    g->disjointSet = newDs(vertices, numVerts, edges, numEdges);
    return g;
}

// void heapToGraph(graph *g, heap *h) {
//     int i = 0;
//     node *n;
//     for (i=0; i < h->size; i++) {
//         //printf("%d ",getNodeValue(n));
//         n = popHeap(h);
//         g->edges[i] = n;
//     }
// }

void printVertices(graph *g) {
    //g->vertices->
}

void makeCorrectSets(ds *d) {

}
