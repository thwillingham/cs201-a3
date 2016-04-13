/*
 * Generic red-black tree class, by John C. Lusth
 *
 *    methods: newRBT, create an empty tree
 *           : addRBT, add an item to the tree
 *           : findRBT, see if an item is in the tree
 *           : freeRBT, dispose of the tree when done
 *
 *    You need to pass in a comparator into the newRBT constructor
 *    It will look something like:
 *
 *    int myComparator(void *x,void *y)
 *        {
 *        // convert the generic operands to their specific types
 *        mytype *a = x;
 *        mytype *b = y;
 *
 *        // now do the comparison
 *        return a->value - b->value;
 *        }
 *
 *    and have the same semantics as strcmp in that if it returns
 *    a value less than zero, the first item is less than the second.
 *    If the first item is equal to the second, then zero should be
 *    returned. Otherwise a positive integer should be returned.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "rbt.h"

/* private class */

typedef struct rbtnode        /* this is a red-black tree node */
    {
    struct rbtnode *parent;
    struct rbtnode *left;
    struct rbtnode *right;
    void *value;            /* generic value pointer */
    int color;
    } rbtnode;

static void Fatal(char *,...);

static rbtnode *newNode(void *);
static rbtnode *findNode(rbtnode *,void *,int (*)(void *,void *));
static rbtnode *insertNode(rbtnode *,void *,int (*)(void *,void *));
static void freeNodes(rbtnode *);
static void rbifixup(rbt *,rbtnode *);
static void rotate(rbt *,rbtnode *);
static rbtnode *uncle(rbtnode *);
static int color(rbtnode *);
static int linear(rbtnode *);

/*********** public interface ************/

rbt *
newRBT(int (*cmp)(void *,void *))
    {
    rbt *t = malloc(sizeof(rbt));
    t->root = 0;
    t->count = 0;
    t->cmp = cmp;
    return t;
    }

void
addRBT(rbt *t,void *v)
    {
    //printf("inserting %s\n",v);
    if (t->root == 0) 
        {
        t->root = newNode(v);
        t->count = 1;
        t->root->color = BLACK;
        }
    else
        {
        rbtnode *n = insertNode(t->root,v,t->cmp);
        t->count += 1;
        rbifixup(t,n);
        }
    }

void *
findRBT(rbt *t,void *v)
    {
    rbtnode *p = findNode(t->root,v,t->cmp);
    if (p == 0)
        return 0;
    else
        return p->value;
    }

void
freeRBT(rbt *t)
    {
    freeNodes(t->root);
    free(t);
    }

/*********** private methods *************/

static rbtnode *
newNode(void *v)
    {
    rbtnode *n = malloc(sizeof(rbtnode));
    if (n == 0) Fatal("out of memory\n");
    n->value = v;
    n->left = 0;
    n->right = 0;
    n->parent = 0;
    n->color = RED;
    return n;
    }

static rbtnode *
insertNode(rbtnode *t,void *v,int (*cmp)(void *,void *))
    {
    //printf("insertNode: current node is %s\n",t->value);
    int side = cmp(v,t->value);
    if (side < 0 && t->left != 0)
        {
        return insertNode(t->left,v,cmp);
        }
    else if (side < 0)
        {
        t->left = newNode(v);
        t->left->parent = t;
        //printf("parent of %s is %s\n",t->left->value,t->left->parent->value);
        return t->left;
        }
    else if (t->right != 0)
        {
        return insertNode(t->right,v,cmp);
        }
    else
        {
        t->right = newNode(v);
        t->right->parent = t;
        return t->right;
        }
    }

static void
freeNodes(rbtnode *n)
    {
    if (n == 0) return;

    free(n->left);
    free(n->right);
    free(n);
    }

static rbtnode *
findNode(rbtnode *t,void *v,int (*cmp)(void *,void *))
    {
    if (t == 0) return 0;
    int side = cmp(v,t->value);
    if (side == 0) return t;
    if (side < 0) return findNode(t->left,v,cmp);
    return findNode(t->right,v,cmp);
    }

static void
rbifixup(rbt *t,rbtnode *x)
    {
    //char *orig = x->value;
    //printf("rbifixup of %s(%s)...\n",x->value,x->parent->value);
    while (x->parent != 0)   //the parent of the root is null
        {
        if (x->parent->color == BLACK)
            x = t->root;
        else if (color(uncle(x)) == RED)
            {
            x->parent->color = BLACK;
            uncle(x)->color = BLACK;
            x->parent->parent->color = RED;
            x = x->parent->parent;
            }
        else
            {
            //uncle must be black
            if (!linear(x))
                {
                rbtnode *oldparent = x->parent;
                rotate(t,x);
                //printf("%s causes a rotation\n",orig);
                x = oldparent;
                }
            x->parent->color = BLACK;
            x->parent->parent->color = RED;
            //printf("rotating parent of %s\n",x->value);
            //printf("parent of %s\n is %s",x->value,x->parent->value);
            //printf("%s causes a rotation\n",orig);
            rotate(t,x->parent);
            }
        }
    x->color = BLACK;
    }

static rbtnode *
uncle(rbtnode *x)
    {
    if (x->parent->parent->left == x->parent)
       return x->parent->parent->right;
    else
       return x->parent->parent->left;
    }

static void
rotate(rbt *t,rbtnode *x)
    {
    /* fix up the grandparent first */
    rbtnode *p = x->parent;
    rbtnode *gp = p->parent;
    if (t->root == p)
        {
        t->root = x;
        x->parent = 0;
        }
    else if (gp->left == p)
        {
        gp->left = x;
        x->parent = gp;
        }
    else
        {
        gp->right = x;
        x->parent = gp;
        }

    /* now do the rotation */
    if (p->left == x) //rotate right
        {
        p->left = x->right;
        if (x->right != 0) x->right->parent = p;
        x->right = p;
        p->parent = x;
        }
    else
        {
        //printf("rotating %s left to %s\n",x->value,p->value);
        p->right = x->left;
        if (x->left != 0) x->left->parent = p;
        x->left = p;
        p->parent = x;
        }
    }

static int
linear(rbtnode *x)
    {
    rbtnode *p = x->parent;
    rbtnode *gp = p->parent;
    return (gp->left == p && p->left == x) || (gp->right == p && p->right == x);
    }

static int
color(rbtnode *x)
    {
    if (x != 0)
        return x->color;
    else
        return BLACK;
    }

static void
Fatal(char *fmt, ...)
    {
    va_list ap;

    fprintf(stderr,"An error occured: ");
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    exit(-1);
    }
