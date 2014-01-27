#include <stdio.h>
#include <stdlib.h>
#include "todoList.h"
#include <string.h>


/********************
this function creates a list manager struct and initializes it.
*********************/
todoList *createListManager() {
  
  todoList *myList;
  myList = malloc(sizeof(todoList));
  myList->activityName = NULL;
  myList->priority = 0;

  return myList;
}


/********************
this function compares the data first by priority and then by name of the activity.
*********************/
int compare(void *dataOne, void *dataTwo) {

	todoList *data1;
  todoList *data2;

  data1 = (todoList *) (dataOne);
  data2 = (todoList *) (dataTwo);

  if (data1->priority < data2->priority)
    return -1;

  if (data1->priority > data2->priority)
    return 1;

  if (data1->priority == data2->priority)
    return strcmp(data1->activityName, data2->activityName);

  return 0;
}


/********************
this function is used by the destroy the data.
*********************/
void copy(void *data) {

}


/********************
this function used to destroy the struct.
*********************/
void destroy(void *data) {

  todoList *R;
  R = (todoList *)(data);
  free(R->activityName);
  free(R);
}


/********************
this function is used to print the data.
*********************/
void print(void *data) {
	todoList *node;
  node = (todoList *)(data);
  printf("%3d - %s\n", node->priority, node->activityName);
}


/********************
this function is used to print any testing.c files.
*********************/
void printTest(void *data) {
  char *node;
  node = (char *)(data);
  printf("%s\n", node);
}


/********************
this function is used to compare any testing.c files.
*********************/
int compareTest(void *dataOne, void *dataTwo) {

  char *data1;
  char *data2;

  data1 = (char *) (dataOne);
  data2 = (char *) (dataTwo);

  return strcmp(data1, data2);
}