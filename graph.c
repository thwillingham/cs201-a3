#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "heap.h"
#include "node.h"
#include "linkedList.h"
#include "queue.h"
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

// void printGraph(graph *g, int root) {
//     printf("%d\n", root);
//     node **vertList = g->vertices;
//     int numVerts = g->numVerts;
//     node **edgeList = g->edges;
//     int numEdges = g->numEdges;
//     node *rootNode = binarySearchArray(vertList, numVerts, root);
//     listNode *ln = rootNode->adj->head;
//     printf("(%d)\n", rootNode->value);
//     int parentValue = rootNode->value;
//     while (ln != NULL) {
//         printf("%d(%d)%d", ln->value->value, parentValue, ln->val);
//         ln = ln->next;
//     }
//
// }

void bfsPrint(graph *g, int root) {
    node **vertList = g->vertices;
    int numVerts = g->numVerts;
    node *rootNode = binarySearchArray(vertList, numVerts, root);
    printf("rootNode: %d", rootNode->value);
    rootNode->color = 1;
    list *q = newLList();
    listNode *lnr = newListNode();
    lnr->value = rootNode;
    addToHead(q, lnr);
    listNode *cur1 = newListNode();
    listNode *cur2 = newListNode();
    listNode *cur3 = newListNode();
    // printf("here\n\n");
    // cur1 = rootNode->adj->head;
    // while (cur1 != 0) {
    //     printf("%d(%d)%d ", cur1->value->value, 0000, cur1->val);
    //     cur1 = cur1->next;
    // }
    // printf("\n");
    int prevHead = -1;
    int currHead = -1;
    int lineNumber = 0;
    while (q->size > 0) {
        cur1 = removeTail(q);
        prevHead = currHead;
        currHead = cur1->parent;
        if (currHead != prevHead) {
            printf("\n%d: ", lineNumber);
            lineNumber++;
        }
        if (cur1->value->value == root) {
            printf("%d", root);
        } else {
            printf("%d(%d)%d ", cur1->value->value, cur1->parent, cur1->val);
        }
        cur2 = cur1->value->adj->head;
        while (cur2 != NULL) {
            cur3 = cur2->next;
            if (cur2->value->color == 0) {
                cur2->value->color = 1;
                cur2->parent = cur1->value->value;
                addToHead(q, cur2);
            }
            cur2 = cur3;
        }
    }
    printf("\n");
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
            lna->val = d->edges[i]->value;
            lna->value = d->edges[i]->leftChild;
            listNode *lnb = newListNode();
            lnb->val = d->edges[i]->value;
            lnb->value = d->edges[i]->rightChild;
            addToTail(d->edges[i]->leftChild->adj, lnb);
            addToTail(d->edges[i]->rightChild->adj, lna);
        }
    }
}
