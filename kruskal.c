#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"
#include "heap.h"
#include "node.h"
#include "linkedList.h"
#include "stack.h"
#include "graph.h"

int main(int argc, char **argv) {
    char* usage = "Usage: ./heapsort [-v info] integers\n";
    int i = 0;
    int f = 0;
    int root = -1;
    if (argc == 1) {
        fprintf(stderr, "Error: No parameters specified.\n");
        fprintf(stderr, "%s", usage);
        return 0;
    }
    for (i=1; i<argc; i++) {
        if (strcmp(argv[i], "-r") == 0) {

        } else {
            f = i;
        }
    }

    heap *h = newHeap();
    h->type = 0; //min-heap
    if (f) {
        if (root == -1) {
            root = importFile(h, argv[f]);
        } else {
            importFile(h,argv[f]);
        }
        heapify(h);
    }
    graph *g = newGraph(h->size);
    heapToGraph(g, h);

    printHeap(h);
    printf("\n");

    return 0;
}
