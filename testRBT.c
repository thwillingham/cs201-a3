/*
 * Test program for RBT class, by John C. Lusth
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"

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

/* test the rbt class */

int
main(int argc,char **argv)
    {
    /* create an empty rbt */
    rbt *t = newRBT(objectComparator);

    /* create some objects */
    object *a = newObject(0);
    object *b = newObject(1);
    object *c = newObject(2);
    object *d = newObject(3);
    object *e = newObject(4);
    object *f = newObject(5);

    /* add them */
    printf("adding object %d\n",a->value);
    addRBT(t,a);
    printf("adding object %d\n",b->value);
    addRBT(t,b);
    printf("adding object %d\n",c->value);
    addRBT(t,c);
    printf("adding object %d\n",d->value);
    addRBT(t,d);
    printf("adding object %d\n",e->value);
    addRBT(t,e);

    /* add another */

    if (findRBT(t,f) == 0)
       {
       printf("object %d not found in tree\n",f->value);
       printf("adding object %d\n",f->value);
       addRBT(t,f);
       }
    else
       printf("object %d was found in tree\n",f->value);

    if (findRBT(t,f) == 0)
       printf("object %d not found in tree\n",f->value);
    else
       printf("object %d was found in tree\n",f->value);

    /* display them */
    displayObject(findRBT(t,f));
    displayObject(findRBT(t,e));
    displayObject(findRBT(t,d));
    displayObject(findRBT(t,c));
    displayObject(findRBT(t,b));
    displayObject(findRBT(t,a));
    printf("\n");

    return 0;
    }
