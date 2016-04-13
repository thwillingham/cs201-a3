#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ds.h"
#include "heap.h"
#include "node.h"
#include "linkedList.h"
#include "listNode.h"
#include "stack.h"

ds *newDs(node **vertices, int numVerts, node **edges, int numEdges) {
    ds *d = (ds *) malloc(sizeof(ds));
    if (d==0) { fprintf(stderr,"out of memory"); exit(-1); }
    d->numVerts = numVerts;
    d->vertices = vertices;
    d->numEdges = numEdges;
    d->edges = edges;
    d->sets = newLList();

    int i = 0;
    // printf("vertexArraySize: %d\n", size);
    // printf("vertex[4] = %d\n", vertices[4]->value);
    for (i=0; i < numVerts; i++) {
        //printf("vertices[%d]\n", i);
        node *n = vertices[i];
        makeSet(d, n);
    }
    // node *a = binarySearchArray(d->vertices, d->numVerts, 214);
    // node *b = binarySearchArray(d->vertices, d->numVerts, 20);
    // //node *s = findSet(t);
    // //printf("tval: %d\n", t->value);
    // //printf("sval: %d\n", s->value);
    // unionSets(d, a, b);
    // a = binarySearchArray(d->vertices, d->numVerts, 214);
    // b = binarySearchArray(d->vertices, d->numVerts, 23);
    // printf("after union:      aset: %d, bset: %d\n", a->value, b->value);
    // unionSets(d, a, b);
    // a = findSet(a);
    // b = findSet(b);
    // printf("before union:     aset: %d, bset: %d\n", a->value, b->value);
    return d;
}

void makeSet(ds *d, node *n) {  // makes set from node and adds to root list
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

void unionSets(ds *d, node *a, node *b) {
    if (a->size > b->size) {
        b->parent = a;
        a->size = a->size + b->size;
        removeFromRootList(d, a);
    } else {
        a->parent = b;
        b->size = b->size + a->size;
        removeFromRootList(d, b);
    }
}

void removeFromRootList(ds *d, node *n) {
    listNode *curr = d->sets->head;
    listNode *temp = NULL;
    while (curr != NULL) {
        if (curr->value == n) {
            temp = curr->next;
            if (curr->previous != NULL) {
                curr->previous->next = curr->next;
            } else {
                d->sets->head = curr->next;
            }
            if (curr->next != NULL) {
                curr->next->previous = curr->previous;
            } else {
                d->sets->tail = curr->previous;
            }
            break;
        }
        curr = curr->next;
    }
}

node *binarySearchArray(node **arr, int arrSize, int i) {
    int f = 0;
    int l = arrSize - 1;
    int m = (f+l)/2;

    while (f <= l) {
        if (arr[m]->value < i) {
            f = m + 1;
        } else if (arr[m]->value == i) {
            //printf("%d found at location %d.\n", i, m+1);
            return arr[m];
            break;
        } else {
            l = m - 1;
        }
        m = (f + l)/2;
    }
    if (f > l) {
        return NULL;
        //    printf("Not found! %d is not present in the list.\n", i);
    }

   return NULL;
}
