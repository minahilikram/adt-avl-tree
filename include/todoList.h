#include "priorityQueue.h"


typedef struct toDoListManager {
  
  char *activityName;
  int priority;
  
}todoList;


/*******************************
createListManager

purpose: This function creates a list and initializes the elements.
preCondition: None.
postCondition: A list is created and initialized.
*********************************/
todoList *createListManager();


/*******************************
compare

purpose: This function comapres the given data first by priority and then by activity name.
preCondition: Given two data items.
postCondition: An interget is returned.
*********************************/
int compare(void *, void *);


/*******************************
copy

purpose: This function is used by the destroy function.
preCondition: None.
postCondition: None.
*********************************/
void copy(void *);


/*******************************
destroy

purpose: This function is used to destroy the struct.
preCondition: Given a struct of type todoListManager.
postCondition: Struct has now been destroyed and does not exist.
*********************************/
void destroy(void *);


/*******************************
print

purpose: This function prints the struct.
preCondition: Struct exists.
postCondition: None.
*********************************/
void print(void *data);


/*******************************
printTest

purpose: This function prints the tree and queue and is used to test the two.
preCondition: Data is given.
postCondition: None.
*********************************/
void printTest(void *data);


/*******************************
print

purpose: This function compares two strings and returns the value that string compare returns.
preCondition: Data is given.
postCondition: None.
*********************************/
int compareTest(void *dataOne, void *dataTwo);