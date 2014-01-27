#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"
#include "todoList.h"
#include <string.h>

int main(int argc, const char * argv[]) {

	queueNode *myQueue;				/*priority queue*/
	FILE *inputFile = NULL;			/*reads from file*/
	char lineBuffer[100];			/*reads upto 100 characters*/
	todoList *myList;				/*list to store the data*/
	char *activityName;				/*temp variable*/
	int priority;					/*temp variable*/
	char *temp;						/*temp variable*/
	int length;						/*finds length of string*/
	int i;							/*loop counter*/
	int menu = 1;					/*menu initialized to 1 to jump into while loop*/

	myQueue = createQueue(compare, copy, destroy);

	if (argc != 2) {
		printf ("Usage Error: please  path/to/executable path/to/input/file\n");
		exit(1);
	}

	inputFile = fopen (argv[1], "r");


	if (inputFile == NULL) {
		printf ( "Error. Input file does not exist!\n");
		exit(1);
	}

	else {
		while (fgets (lineBuffer, 100, inputFile) != NULL) {
			if (lineBuffer[strlen(lineBuffer)-1] == '\n')
				lineBuffer[strlen(lineBuffer)-1] = '\0';

			myList = createListManager();

			activityName = strtok (lineBuffer," ");
			myList->activityName = malloc((strlen(activityName)+1) * (sizeof(char)));
			strncpy(myList->activityName, activityName, strlen(activityName)+1);
		
    		temp = strtok (NULL, " ");
			
			if (temp == NULL)
    			priority = 100;
    		
    		if (temp != NULL) {
    			length = strlen(temp)-1;
    			for (i = 0; i <= length; i++) {
    				if (temp[i] >= '0' && temp[i] <= '9')
    					priority = atoi(temp);
    				else
    					priority = 100;
    			}
    		}
    		if (priority > 0 && priority < 101)
    			myList->priority = priority;
    		else
    			priority = 100;
    			myList->priority = priority;

			enqueue(myQueue, myList);
		}
	}

	printf("\n");
	printQueue(myQueue, &print);

	while (menu > 0 && menu < 3) {
	
	printf("\n[1] Add\n");
	printf("[2] Delete\n");
	printf("[3] Exit\n");
	fgets (lineBuffer, 100, stdin);

	menu = atoi(lineBuffer);

		switch(menu) {

			case 1:
				printf("please enter an activity and priority with a space in between, eg. eat 1. If no priority is entered it will be given a priority of 100.\n"); 
				printf("*note if the activity is not entered in the given format it will not be added.\n");
				fgets (lineBuffer, 100, stdin);
				if (lineBuffer[strlen(lineBuffer)-1] == '\n')
					lineBuffer[strlen(lineBuffer)-1] = '\0';

				myList = createListManager();

				activityName = strtok (lineBuffer," ");
				myList->activityName = malloc((strlen(activityName)+1) * (sizeof(char)));
				strncpy(myList->activityName, activityName, strlen(activityName)+1);
			
	    		temp = strtok (NULL, " ");
				
				if (temp == NULL)
	    			priority = 100;
	    		
	    		if (temp != NULL) {
	    			length = strlen(temp)-1;
	    			for (i = 0; i <= length; i++) {
	    				if (temp[i] >= '0' && temp[i] <= '9')
	    					priority = atoi(temp);
	    				else
	    					priority = 100;
	    			}
	    		}
	    		if (priority > 0 && priority < 101)
	    			myList->priority = priority;
	    		else
	    			priority = 100;
	    			myList->priority = priority;

				enqueue(myQueue, myList);
				printQueue(myQueue, &print);
				printf("\n");
				break;

			case 2:
				dequeue(myQueue);
				printQueue(myQueue, &print);
				printf("\n");
				break;
		}
	}

	return 0;
}