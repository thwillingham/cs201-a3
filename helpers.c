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

int importFile(heap *h, char* fName) { // read ints from file into heap
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
      //s = readToken(fp);
      w = 1;
      //printf("%d, %d, %d\n", f, t, w);
      //continue;
    } else {
        w = atoi(s);
        readToken(fp);
        //if (!feof(fp)) {
          //  s = readToken(fp);
        //}
        //printf("%d, %d, %d\n", f, t, w);
        //continue;
    }

    printf("%d, %d, %d\n", f, t, w); // insert into graph
    insertItem(h, f, t, w);
    if (!feof(fp)) {
        s = readToken(fp);
    }
  }
  return r;
}
