#include <stdlib.h>
#include <stdio.h>
#include "priorityQueue.h"
#include "todoList.h"

int main() {
	
	char *array[] = {"mona", "is", "the", "best", "yes", "and", "that", "is", "the", "total", "truth", "ikram", "a3"};
	queueNode *myQueue;		/*creates a queue*/
	int i;					/*interator to add elements to the queue*/

	myQueue = createQueue(compareTest, copy, destroy);

	for (i = 0; i < 13; i++)
		enqueue(myQueue, array[i]);

	printf("\nafter elements added...\n");
	printQueue(myQueue, printTest);

	dequeue(myQueue);
	dequeue(myQueue);
	dequeue(myQueue);
	dequeue(myQueue);
	dequeue(myQueue);

	printf("\nafter 4 elements deleted...\n");
	printQueue(myQueue, printTest);

	destroyQueue(myQueue);

	return 0;
}