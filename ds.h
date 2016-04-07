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
    list *sets;
    node **vertices;
};

extern ds *newDs(node **vertices, int numVerts);
extern void makeSet(ds *d, node *n);
extern node *findSet(node *n);
extern void removeFromRootList(node *n);
extern node *binarySearchArray(node **arr, int numVerts, int i);


#endif
