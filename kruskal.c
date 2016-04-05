#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"
#include "heap.h"
#include "node.h"
#include "linkedList.h"
#include "stack.h"

int main(int argc, char **argv)
{
    
    char* usage = "Usage: ./heapsort [-v info] integers\n";
    int i = 0;
    char* file;
    int f = 0;
    if (argc == 1)
    {
        fprintf(stderr, "Error: No parameters specified.\n");
        fprintf(stderr, "%s", usage);
        return 0;
    }
    for (i=1; i<argc; i++)
    {
        if (strcmp(argv[i], "-r") == 0)
        {
            
        }else
        {
            file = argv[i];
            f = i;
        }
    }

    heap *h = newHeap();
    h->type = 0; //min-heap
    if (f)
    {
        importFile(h,argv[f]);
    } /*else if (d == 1 && f == 0)
    {
        fprintf(stderr, "Error: Invalid parameter combination.\n");
        fprintf(stderr, "%s", usage);
        return 0;
    }*/
    heapify(h);
    printHeap(h);
    printf("\n");
    
    return 0;
}
