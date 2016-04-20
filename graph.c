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
#include "array.h"
#include "rbt.h"
#include "helpers.h"


graph *newGraph(array *vertices, array *edges) {
    graph *g = (graph *) malloc(sizeof(graph));
    if (g==0) { fprintf(stderr,"out of memory"); exit(-1); }

    g->vertices = vertices;
    g->edges = edges;
    g->disjointSet = newDs(vertices, edges);
    return g;
}

void makeCorrectSets(ds *d) {
    int i = 0;
    node *a = NULL;
    node *b = NULL;
    node *temp = NULL;
    for (i=0; i < d->edges->size; i++) {
        temp = d->edges->store[i];
        a = findSet(temp->leftChild);
        b = findSet(temp->rightChild);
        if (a != b) {
            unionSets(d, a, b);
            listNode *lna = newListNode();
            lna->val = temp->value;
            lna->value = temp->leftChild;

            listNode *lnb = newListNode();
            lnb->val = temp->value;
            lnb->value = temp->rightChild;

            addToHead(temp->leftChild->adj, lnb);
            addToHead(temp->rightChild->adj, lna);
        }
    }
}













void bfsPrint(graph *g, int root) {
    /* setup */
    rbt *t = newRBT(listNodeComparator);
    array *a = newArray(listNodeComparator);
    list *q = newLList();
    int i = 0, lineNumber = 0, treeWeight = 0, reachable = 1;

    /* get root node */
    node *rootNode = binarySearchArray(g->vertices, root);
    rootNode->color = 1;

    /* add root to rbt, array, and queue */
    listNode *lnr = newListNode(); // listNode for adding rootNode to queue
    lnr->value = rootNode;
    lnr->parentNode = lnr;
    lnr->color = 1;
    addToHead(q, lnr);
    addArray(a, lnr);
    addRBT(t, lnr);

    /* initialize temp variables */
    listNode *cur = NULL, *adjCur = NULL, *temp = NULL;

    while (q->size > 0) {
        cur = removeTail(q); // get next item in queue
        if (findRBT(t, cur->parentNode) != 0) { // node is in tree
            //printf("arraySize: %d", a->size);
            printf("%d: ", lineNumber);
            lineNumber++;
            if (cur->value->value == root) {
                printf("%d;", root);
            } else {
                sortArray(a);
                for (i = 0; i < a->size; i++) {
                    listNode *ln = a->store[i];
                    printf("%d(%d)%d; ", ln->value->value, ln->parentNode->value->value, ln->val);
                    treeWeight += ln->val;
                    reachable++;
                }
            }
            printf("\n");
            freeRBT(t);
            freeArray(a);
            t = newRBT(listNodeComparator);
            a = newArray(listNodeComparator);
            if (cur->value->value != root) {
                addRBT(t, cur);
                addArray(a, cur);
            }
        } else {
            addRBT(t, cur);
            addArray(a, cur);
            //cur->value->color = 1;
        }

        adjCur = cur->value->adj->head;
        while (adjCur != NULL) {
            temp = adjCur->next;
            if (adjCur->value->color == 0) {
                adjCur->value->color = 1;
                adjCur->parentNode = cur;
                adjCur->parent = cur->value->value;
                addToHead(q, adjCur);
                //printf("adjCurValue: %d", adjCur->value->value);
            }
            adjCur = temp;
        }
    }
    sortArray(a);
    printf("%d: ", lineNumber);
    for (i = 0; i < a->size; i++) {
        listNode *ln = a->store[i];
        printf("%d(%d)%d; ", ln->value->value, ln->parent, ln->val);
        treeWeight += ln->val;
        reachable++;
    }
    printf("\n");
    freeRBT(t);
    freeArray(a);
    printf("weight: %d\n", treeWeight);
    printf("unreachable: %d\n", g->vertices->size - reachable);
}
