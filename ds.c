#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ds.h"
#include "heap.h"
#include "node.h"
#include "linkedList.h"
#include "listNode.h"
#include "stack.h"

ds *newDs(node **vertices, int numVerts) {
    ds *d = (ds *) malloc(sizeof(ds));
    if (d==0) { fprintf(stderr,"out of memory"); exit(-1); }
    d->numVerts = numVerts;
    d->vertices = vertices;
    d->sets = newLList();

    int i = 0;
    int size = sizeof(&vertices)/sizeof(vertices[0]);
    // printf("vertexArraySize: %d\n", size);
    // printf("vertex[4] = %d\n", vertices[4]->value);
    for (i=0; i < numVerts; i++) {
        //printf("vertices[%d]\n", i);
        makeSet(d, vertices[i]);
    }
    node *t = binarySearchArray(d->vertices, d->numVerts, 214);
    printf("tval: %d\n", t->value);
    return d;
}

void makeSet(ds *d, node *n) {
    listNode *ln = newListNode();
    ln->value = n;
    ln->value->parent = n;
    addToTail(d->sets, ln);
}

node *findSet(node *n) {
    if (n->parent == n) {
        return n;
    } else {
        n->parent = findSet(n->parent);
        return n->parent;
    }
}

void unionSets(node *a, node *b) {
    if (a->size > b->size) {
        b->parent = a;
        removeFromRootList(a);
    } else {
        a->parent = b;
        removeFromRootList(b);
    }
}

void removeFromRootList(node *n) {

}

node *binarySearchArray(node **arr, int arrSize, int i) {
    int f = 0;
    int l = arrSize - 1;
    int m = (f+l)/2;

   while (f <= l) {
      if (arr[m]->value < i)
         f = m + 1;
      else if (arr[m]->value == i) {
         printf("%d found at location %d.\n", i, m+1);
         return arr[m];
         break;
      }
      else
         l = m - 1;

      m = (f + l)/2;
   }
   if (f > l)
      printf("Not found! %d is not present in the list.\n", i);

   return NULL;
}
