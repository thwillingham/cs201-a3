OBJS=kruskal.o heap.o node.o linkedList.o queue.o stack.o listNode.o helpers.o scanner.o graph.o ds.o rbt.o array.o
kruskal: $(OBJS)
	gcc -Wall -g $(OBJS) -o kruskal

kruskal.o: kruskal.c heap.h helpers.h node.h linkedList.h stack.h ds.h rbt.h array.h
	gcc -Wall -g -c kruskal.c
heap.o: heap.c heap.h helpers.h node.h linkedList.h stack.h listNode.h queue.h
	gcc -Wall -g -c heap.c
node.o: node.c node.h
	gcc -Wall -g -c node.c
linkedList.o: linkedList.c linkedList.h
	gcc -Wall -g -c linkedList.c
queue.o: queue.c linkedList.h listNode.h queue.h
	gcc -Wall -g -c queue.c
stack.o: stack.c linkedList.h stack.h listNode.h
	gcc -Wall -g -c stack.c
listNode.o: listNode.c listNode.h
	gcc -Wall -g -c listNode.c
helpers.o: helpers.c helpers.h node.h heap.h rbt.h array.h
	gcc -Wall -g -c helpers.c
graph.o: graph.c graph.h node.h heap.h ds.h
	gcc -Wall -g -c graph.c
ds.o: ds.c ds.h graph.h heap.h node.h linkedList.h stack.h
	gcc -Wall -g -c ds.c
rbt.o: rbt.c rbt.h node.h
	gcc -Wall -g -c rbt.c
array.o: array.h
	gcc -Wall -g -c array.c








clean:
	rm -f ./*.o

run: kruskal
	./kruskal -r 0 testInput

test: heapsort
	./heapsort
	./heapsort -v
	./heapsort -v -d
	./heapsort -v -d testInts
	./heapsort -d
	./heapsort -d testInts
	./heapsort testInts
	./heapsort foobar
