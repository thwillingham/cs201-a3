#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "heap.h"

extern int compare(int type, node *a, node *b);
extern void importFile(heap *h, char* fName);

#endif
