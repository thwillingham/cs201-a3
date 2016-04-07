#ifndef DS_H
#define DS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"
#include "node.h"
#include "linkedList.h"
#include "stack.h"

typedef struct ds ds;
struct ds {
    int numVerts;
    int numEdges;
    list *sets;
    node **vertices;
    node **edges;
};

extern ds *newDs(node **vertices, int numVerts, node **edges, int numEdges);
extern void makeSet(ds *d, node *n);
extern node *findSet(node *n);
extern void unionSets(ds *d, node *a, node *b);
extern void removeFromRootList(ds * d, node *n);
extern node *binarySearchArray(node **arr, int numVerts, int i);


#endif
