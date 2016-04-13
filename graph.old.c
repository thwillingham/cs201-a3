void bfsPrintOld(graph *g, int root) {
    /* get root node */
    node *rootNode = binarySearchArray(g->vertices, root);
    rootNode->color = 1;

    /* setup queue */
    list *q = newLList();  // queue for printing
    listNode *lnr = newListNode(); // listNode for adding rootNode to queue
    lnr->value = rootNode;
    addToHead(q, lnr);

    /* initialize temp variables */
    listNode *cur1 = newListNode();
    listNode *cur2 = newListNode();
    listNode *cur3 = newListNode();

    while (q->size > 0) {
        cur1 = removeTail(q); // get next item in queue
        printf("%d(%d)%d     \n", cur1->value->value, 0, cur1->val);
        cur2 = cur1->value->adj->head; //set to root of cur1 adjacency list
        while (cur2 != NULL) {
            cur3 = cur2->next; // save next node since current node pointers may be changed
            if (cur2->value->color == 0) { // if this vertex hasn't been seen
                cur2->value->color = 1;
                addToHead(q, cur2);  // add to queue
            }
            cur2 = cur3;
        }
    }
}
