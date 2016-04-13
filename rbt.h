#ifndef RBT_H
#define RBT_H

/*
 * Red-black tree methods, by John C. Lusth
 *
 *    This is the public interface for nodes/red-black trees
 *
 *    See rbt.c for a description
 */

typedef struct rbtnode rbtnode;

typedef struct rbt
    {
    rbtnode *root;
    int count;
    int (*cmp)(void *,void *);
    } rbt;

/************ Public Interface **************/

/* constructors */

extern rbt *newRBT(int (*)(void *,void *));

/* mutators */

extern void addRBT(rbt *,void *);
extern void freeRBT(rbt *);

/* accessors */

void *findRBT(rbt *,void *);

/* color constants */

#define RED 0
#define BLACK 1

#endif
