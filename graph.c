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
    int numVerts = g->vertices->size;
    node *rootNode = binarySearchArray(g->vertices, root);
    //printf("rootNode: %d", rootNode->value);
    rootNode->color = 1;
    list *q = newLList();
    listNode *lnr = newListNode();
    lnr->value = rootNode;
    addToHead(q, lnr);
    listNode *cur1 = newListNode();
    listNode *cur2 = newListNode();
    listNode *cur3 = newListNode();
    int prevHead = -1;
    int currHead = -1;
    int firstNodeInLine = root;
    int lineNumber = 1;
    printf("0: %d", lnr->value->value);
    rbt *vertTree = newRBT(arrayEdgeNodeComparator);
    array *edgeArray = newArray(arrayEdgeNodeComparator);
    int i = 0;
    while (q->size > 0) {
        cur1 = removeTail(q); // get next node in queue
        // if (findRBT(vertTree, cur1->value->parent) == 0) {
        //     addRBT(vertTree, cur1->value->parent);
        //     addArray(edgeArray, cur1->value);
        // } else {
        //     sortArray(edgeArray);
        //     printf("\n%d: ", lineNumber);
        //     for (i=0; i<edgeArray->size; i++) {
        //         node *t = edgeArray->store[i];
        //         printf("%d(%d)%d ", t->value, t->parent->value, 2);
        //         removeTail(q);
        //     }
        //     vertTree = newRBT(arrayEdgeNodeComparator);
        //     edgeArray = newArray(arrayEdgeNodeComparator);
        //     addRBT(vertTree, cur1->value);
        //     addArray(edgeArray, cur1->value);
        // }

        prevHead = currHead;
        currHead = cur1->parent;
        if (cur1->parent == firstNodeInLine) {
            printf("\n%d: ", lineNumber);
            lineNumber++;
            firstNodeInLine = cur1->value->value;
        }
        if (cur1->value->value != root) {
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
    node *temp = NULL;
    //printf("here0\n");
    for (i=0; i < d->edges->size; i++) {
        //("here1\n");
        // a = findSet(binarySearchArray(d->vertices, d->numVerts, d->edges[i]->from));
        // b = findSet(binarySearchArray(d->vertices, d->numVerts, d->edges[i]->to));
        temp = d->edges->store[i];
        //printf("val: %d\n", temp->parent);
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

            addToTail(temp->leftChild->adj, lnb);
            addToTail(temp->rightChild->adj, lna);
        }
    }
}













void bfsPrintOld(graph *g, int root) {
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
                for (i = 0; i < a->size; i++) {
                    listNode *ln = a->store[i];
                    printf("%d(%d)%d; ", ln->value->value, ln->parent, ln->val);
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
            cur->value->color = 1;
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
