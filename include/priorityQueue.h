#ifndef BINTREE_GUARD2
#define BINTREE_GUARD2


#include "queueNode.h"


/*******************************
createQueue

purpose: This function creates a queue.
preCondition: Accepts three functions.
postCondition: Queue is created and initalized.
*********************************/
queueNode *createQueue(int (*compare) (void *, void *), void (* copy) (void *), void (* destroy) (void *));


/*******************************
enqueue

purpose: This function adds elements to the queue.
preCondition: Accepts data.
postCondition: Queue is longer by one element.
*********************************/
void enqueue(queueNode *myQueue, void *data);


/*******************************
printQueue

purpose: This function prints the queue by priority.
preCondition: Accepts queue.
postCondition: None.
*********************************/
void printQueue(queueNode *myQueue, void (*print)(void *data));


/*******************************
printQueue

purpose: This function removes items from the queue by priority.
preCondition: Accepts queue.
postCondition: Queue is smaller by one element.
*********************************/
void dequeue(queueNode *myQueue);


/*******************************
destroyQueue

purpose: This function destroys the queue and frees memory.
preCondition: Accepts queue.
postCondition: Queue no longer exists.
*********************************/
void destroyQueue(queueNode *myQueue);

#endif