#ifndef DS_H
#define DS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"
#include "node.h"
#include "linkedList.h"
#include "stack.h"
#include "stack.h"
#include "array.h"

typedef struct ds ds;
struct ds {
    list *sets;
    array *vertices;
    array *edges;
};

extern ds *newDs(array *vertices, array *edges);
extern void makeSet(ds *d, node *n);
extern node *findSet(node *n);
extern void unionSets(ds *d, node *a, node *b);
extern void removeFromRootList(ds * d, node *n);
extern node *binarySearchArray(array *a, int i);


#endif
