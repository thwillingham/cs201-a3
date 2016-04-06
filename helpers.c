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
  int r = 0;
  fp = fopen(fname, "r");
  if (fp == NULL) {
    perror("error\n");
    exit(-1);
  }
  s = readToken(fp);
  if (!feof(fp)) {
    r = atoi(s);
  }
  while (!feof(fp)) {
    f = atoi(s);
    t = atoi(readToken(fp));
    s = readToken(fp);
    if (strcmp(s, ";") == 0) {
      w = 1;
    } else {
        w = atoi(s);
        readToken(fp);
    }

    printf("%d, %d, %d\n", f, t, w); // insert into graph
    /* insert vertices into vertList if not already there */
    if (isInList(vertList, f) == 0) { //if f vertex isn't in linkedList, add it.
        node *frm = newNode();
        frm->value = f;
        listNode* lnf = newListNode();
        lnf->value = frm;
        addToTail(vertList, lnf);
    }
    if (isInList(vertList, t) == 0) { //if t vertex isn't in linkedList, add it.
        node *to = newNode();
        to->value = t;
        listNode* lnt = newListNode();
        lnt->value = to;
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
  return r;
}
