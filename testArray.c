/*
 * Test program for Array class, by John C. Lusth
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/* a sample object class */

typedef struct object
    {
    int value;
    } object;

/* a constructor for objects */

object *
newObject(int v)
    {
    object *o = malloc(sizeof(object)); //warning: return value not checked!
    o->value = v;
    return o;
    }

/* a comparator for sorting */

int
objectComparator(void *o1,void *o2)
    {
    object *a = o1;
    object *b = o2;

    return a->value - b->value; //ascending order, flip for descending
    }

/* a display method */

void
displayObject(object *n)
    {
    printf("%d ",n->value);
    }

/* test the array class */

int
main(int argc,char **argv)
    {
    int i;

    /* create an empty array */
    array *a = newArray(objectComparator);

    /* add some objects */
    for (i = 5; i >= 0; --i)
        addArray(a,newObject(i));

    /* display them */
    printf("before sorting: ");
    for (i = 0; i < a->size; ++i)
        displayObject(a->store[i]);
    printf("\n");

    /* now sort in ascending order */

    sortArray(a);

    /* display them again */
    printf("after sorting:  ");
    for (i = 0; i < a->size; ++i)
        displayObject(a->store[i]);
    printf("\n");

    return 0;
    }
