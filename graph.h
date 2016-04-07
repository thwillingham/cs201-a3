#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"
#include "node.h"
#include "linkedList.h"
#include "stack.h"
#include "ds.h"

typedef struct graph graph;
struct graph {
    //int size;
    int numVerts;
    int numEdges;
    ds *disjointSet;
    node **vertices;
    node **edges;
};

extern graph *newGraph(node **vertices, int numVerts, node **edges, int numEdges);
extern void makeCorrectSets(ds *d);
extern void heapToGraph(graph *g, heap *h);

#endif
