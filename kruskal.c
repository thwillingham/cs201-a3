#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"
#include "heap.h"
#include "node.h"
#include "linkedList.h"
#include "stack.h"
#include "graph.h"
#include "ds.h"
#include "rbt.h"
#include "array.h"

int main(int argc, char **argv) {
    char* usage = "Usage: ./heapsort [-v info] integers\n";
    int i = 0;
    int f = 0;
    int r = 0;
    int root = 0;
    if (argc == 1) {
        fprintf(stderr, "Error: No parameters specified.\n");
        fprintf(stderr, "%s", usage);
        return 0;
    }
    for (i=1; i<argc; i++) {
        if (strcmp(argv[i], "-r") == 0) {
            r = 1;
            root = atoi(argv[i+1]);
            i++;
        } else {
            f = i;
        }
    }

    heap *e = newHeap();
    e->type = 0; //min-heap
    heap *v = newHeap();
    v->type = 0; //min-heap
    list *vertList = newLList();
    list *edgeList = newLList();
    rbt *edgeTree = newRBT(rbtEdgeNodeComparator);
    array *edgeArray = newArray(arrayEdgeNodeComparator);
    rbt *vertTree = newRBT(arrayEdgeNodeComparator);
    array *vertArray = newArray(arrayEdgeNodeComparator);

    if (f) {
        if (r == 0) {
            root = importFile(argv[f], edgeTree, edgeArray, vertTree, vertArray); // O(v + e)
        } else {
            importFile(argv[f], edgeTree, edgeArray, vertTree, vertArray); // O(v + e)
        }
        //heapify(e);
    }
    graph *g = newGraph(vertArray, edgeArray); // O(v)
    makeCorrectSets(g->disjointSet); // O(e)
    bfsPrintOld(g, root);



    // int numVerts = vertList->size;
    // int numEdges = edgeList->size;
    // ////printf("verts: %d, Edges: %d\n", numVerts, numEdges);
    // node **vertArray = nodeListToArray(vertList); // O(v)
    // node **edgeArray = nodeListToArray(edgeList); // O(v)
    // graph *g = newGraph(vertArray, numVerts, edgeArray, numEdges); // O(v)
    // makeCorrectSets(g->disjointSet); // O(e)
    // ////printGraph(g, root); // O(v + e)
    // bfsPrint(g, root);







    //heapToGraph(g, e);
    //printHeap(e);
    //printf("\n");
    return 0;
}
