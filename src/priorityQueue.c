#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"


/********************
this function creates a queue.
*********************/
queueNode *createQueue(int (*compare) (void *, void *), void (* copy) (void *), void (* destroy) (void *)) {

    queueNode * myQueue;
    myQueue = malloc(sizeof(queueNode));
    myQueue->myTree = createTree(compare, copy, destroy);
    
    return myQueue;
}


/********************
this function adds items to the tree.
*********************/
void enqueue(queueNode *myQueue, void *data) {
    
    myQueue->myTree->root = addToTree(myQueue->myTree->root, data, myQueue->myTree->compareptr);
}


/********************
this function prints the qeueue.
*********************/
void printQueue(queueNode *myQueue, void (*print)(void *data)) {

	if (myQueue->myTree->root->data == NULL)
		return;
    printInOrder(myQueue->myTree->root, print);
}


/********************
this function removes items from the queue based on priority.
*********************/
void dequeue(queueNode *myQueue) {
	
	treeNode *node;
	node = minValueNode(myQueue->myTree->root);
	deleteNode(myQueue->myTree->root, node->data, myQueue->myTree->compareptr);
}


/********************
this function destroys the queue.
*********************/
void destroyQueue(queueNode *myQueue) {

	destroyTree(myQueue->myTree);
    free(myQueue);
}