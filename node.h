#ifndef NODE_H
#define NODE_H
typedef struct node node;
struct node
    {
        int value;
        int from;
        int to;
        struct node *parent;
        struct node *leftChild;
        struct node *rightChild;
    };

extern node *newNode(void);
extern void setNodeValue(node *n, int value);
extern int getNodeValue(node *n);
extern void setNodeLeftChild(node *n, node *leftChild);
extern node *getNodeLeftChild(node *n);
extern void setNodeRightChild(node *n, node *rightChild);
extern node *getNodeRightChild(node *n);
extern void setNodeParent(node *n, node *parent);
extern node *getNodeParent(node *n);
extern void swapNodeValue(node *a, node *b);
extern int getNodeFrom(node *n);
extern void setNodeFrom(node *n, int f);
extern int getNodeTo(node *n);
extern void setNodeTo(node *n, int t);

#endif
