#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "heap.h"
#include "node.h"
#include "linkedList.h"
#include "listNode.h"
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

void printGraph(graph *g, int root) {
    printf("%d\n", root);
    node **vertList = g->vertices;
    int numVerts = g->numVerts;
    node **edgeList = g->edges;
    int numEdges = g->numEdges;
    node *rootSet = binarySearchArray(vertList, numVerts, root);

}

void makeCorrectSets(ds *d) {
    int i = 0;
    node *a = NULL;
    node *b = NULL;
    for (i=0; i < d->numEdges; i++) {
        // a = findSet(binarySearchArray(d->vertices, d->numVerts, d->edges[i]->from));
        // b = findSet(binarySearchArray(d->vertices, d->numVerts, d->edges[i]->to));
        a = findSet(d->edges[i]->leftChild);
        b = findSet(d->edges[i]->rightChild);
        if (a != b) {
            unionSets(d, a, b);
            listNode *lna = newListNode();
            lna->value = d->edges[i]->leftChild;
            listNode *lnb = newListNode();
            lnb->value = d->edges[i]->rightChild;
            addToTail(d->edges[i]->leftChild->adj, lnb);
            addToTail(d->edges[i]->rightChild->adj, lna);
        }
    }
}
