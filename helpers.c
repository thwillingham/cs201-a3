#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
#include "helpers.h"
#include "node.h"
#include "heap.h"
#include "rbt.h"
#include "array.h"
#include "listNode.h"

int compare(int type, node *a, node *b) // compare nodes based on heap type (max/min)
{

    if (!type) //min heap
    {
        return a->value>b->value;
    } else if (type) //max heap
    {
        return a->value<b->value;
    }
    return 0;
}

int importFile(char* fName, rbt *edgeTree, array *edgeArray, rbt *vertTree, array *vertArray) { // read ints from file into heap
  char* fname = fName;
  FILE *fp;
  char* s;
  int f = 0, t = 0, w = 0, root = 0;
  node *nodeFrom = NULL, *nodeTo = NULL, *nodeEdge = NULL, *nf = NULL, *nt = NULL, *e = NULL;
  fp = fopen(fname, "r");
  if (fp == NULL) {
    perror("error\n");
    exit(-1);
  }
  s = readToken(fp);
  if (!feof(fp)) {
    root = atoi(s);
    } else {
        fprintf(stderr, "Error: Input file is empty.\n");
        exit(0);
    }
  while (!feof(fp)) {
    f = atoi(s);
    t = atoi(readToken(fp));
    s = readToken(fp);
    if (strcmp(s, ";") == 0) {
      w = 1;
    } else {
        w = atoi(s);
        s = readToken(fp);
    }


    e = newNode();  //edge node
    e->value = w;
    e->from = f;
    e->to = t;


    nodeEdge = findRBT(edgeTree, e);
    if (nodeEdge == 0) {
        addRBT(edgeTree, e);
        addArray(edgeArray, e);
        nodeEdge = e;

        nf = newNode(); //vertex from node
        nf->value = f;
        nt = newNode(); //vertex to node
        nt->value = t;

        nodeFrom = findRBT(vertTree, nf);
        if (nodeFrom == 0) {
            addRBT(vertTree, nf);
            addArray(vertArray, nf);
            nodeFrom = nf;
        }

        nodeTo = findRBT(vertTree, nt);
        if (nodeTo == 0) {
            addRBT(vertTree, nt);
            addArray(vertArray, nt);
            nodeTo = nt;
        }
        nodeEdge->leftChild = nodeFrom;
        nodeEdge->rightChild = nodeTo;
    }

    if (!feof(fp)) {
        s = readToken(fp);
    }
  }
  freeRBT(edgeTree);
  freeRBT(vertTree);
  sortArray(edgeArray);
  sortArray(vertArray);
  return root;
}


node **nodeListToArray(list *l) {
    int i = 0;
    int size = l->size;
    node **edges = malloc(size * sizeof *edges);
    listNode *ln = l->head;
    while (ln != NULL) {
        edges[i] = ln->value;
        ln = ln->next;
        i++;
    }
    return edges;
}

int rbtEdgeNodeComparator(void *e1, void *e2) {
    node *n1 = e1;
    node *n2 = e2;
    if (n1->from == n2->from && n1->to == n2->to) {  // equals current edge
        return 0;
    } else if (n1->from == n2->to && n1->to == n2->from) { // equals current edge reversed
        return 0;
    } else if (n1->from + n1->to < n2->from + n2->to) { // combined value is less than combined value of current edge
        return -1;
    } else if (n1->from + n1->to > n2->from + n2->to) { // combined value is greater than combined value of current edge
        return 1;
    } else if (n1->from + n1->to == n2->from + n2->to) { // combined value is equal to combined value of current edge
        int a = 0;
        int b = 0;
        if (n1->from < n1->to) { // get minimum vertex in from edge
            a = n1->from;
        } else {
            a = n1->to;
        }
        if (n2->from < n2->to) { // get minimum vertex in to edge
            b = n2->from;
        } else {
            b = n2->to;
        }
        if (a < b) { // compare lesser vertices of both edges
            return -1;
        } else {
            return 1;
        }
    } else {
        return 1;
    }
}

int arrayEdgeNodeComparator(void *e1, void *e2) {
    node *n1 = e1;
    node *n2 = e2;
    if (n1->value == n2->value) {
        return 0;
    } else if (n1->value < n2->value) {
        return -1;
    } else {
        return 1;
    }
}

int listNodeComparator(void *e1, void *e2){
    listNode *n1 = e1;
    listNode *n2 = e2;
    if (n1->val == n2->val) {
        return 0;
    } else if (n1->val < n2->val) {
        return -1;
    } else {
        return 1;
    }
}
