#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
#include "helpers.h"
#include "node.h"
#include "heap.h"

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

int importFile(heap *h, list *vertList, list *edgeList, char* fName) { // read ints from file into heap
  char* fname = "testInput";
  FILE *fp;
  char* s;
  int f = 0;
  int t = 0;
  int w = 0;
  int root = 0;
  fp = fopen(fname, "r");
  if (fp == NULL) {
    perror("error\n");
    exit(-1);
  }
  s = readToken(fp);
  if (!feof(fp)) {
    root = atoi(s);
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

    printf("\nEdge Read From File: %d, %d, %d\n", f, t, w); // insert into graph
    /* insert vertices into vertList if not already there */
    if (isInList(vertList, f) == 0) { //if f vertex isn't in linkedList, add it.
        listNode* lnf = newListNode();
        lnf->val = f;
        addToTail(vertList, lnf);
    }
    if (isInList(vertList, t) == 0) { //if t vertex isn't in linkedList, add it.
        listNode* lnt = newListNode();
        lnt->val = t;
        addToTail(vertList, lnt);
    }
    if (edgeIsInList(edgeList, f, t) == 0) { //if f-t or t-f edge isn't in linkedList, add it.
        node *e = newNode();
        e->value = w;
        e->from = f;
        e->to = t;
        listNode *lne = newListNode();
        lne->value = e;
        addToTail(edgeList, lne);
    }
    //insertItem(h, f, t, w);

    if (!feof(fp)) {
        s = readToken(fp);
    }
  }
  return root;
}

node ** getSortedVertexArray(list *l) {
    heap *h = newHeap();
    listNode *ln = l->head;
    while (ln != NULL) {
        insertItem(h, 0, 0, ln->val);
        ln = ln->next;
    }
    // all vertices should be on heap now
    int i = 0;
    int size = h->size;
    node **vertices = malloc(size * sizeof *vertices);
    node *n = popHeap(h);
    while (n != NULL) {
        vertices[i] = n;
        n = popHeap(h);
        i++;
    }
    // for (i=0; i < size; i++) {
    //     printf("vertex %d: %d\n", i+1, vertices[i]->value);
    // }
    return vertices;
}

node ** getSortedEdgeArray(list *l) {
    heap *h = newHeap();
    listNode *ln = l->head;
    while (ln != NULL) {
        insertNode(h, ln->value);
        ln = ln->next;
    }
    // all vertices should be on heap now
    int i = 0;
    int size = h->size;
    node **edges = malloc(size * sizeof *edges);
    node *n = popHeap(h);
    while (n != NULL) {
        edges[i] = n;
        n = popHeap(h);
        i++;
    }
    // for (i=0; i < size; i++) {
    //     printf("edge %d: %d - %d, %d\n", i+1, edges[i]->from, edges[i]->to, edges[i]->value);
    //
    // }
    return edges;
}
