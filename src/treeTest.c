#include <stdio.h>
#include <stdlib.h>
#include "avlTree.h"
#include "priorityQueue.h"
#include "todoList.h"
#include <string.h>


int main() {

	char *array[] = {"mona", "is", "the", "best", "yes", "and", "that", "is", "the", "total", "truth", "ikram", "a3"};
	tree *myTree;		/*decalares a variable of type tree*/
	int i;				/*used in for-loop to add elements to the tree*/
	treeNode *node;		/*used to find the minimum value of the tree in order to delete it*/
	int h;				/*used to hold the value of height of the tree*/

	myTree = createTree(&compareTest, &copy, &destroy);		/*tree created*/

	for (i = 0; i < 13; i++) {							/*adding elements from the array to the tree*/
		myTree->root = addToTree(myTree->root, array[i], &compareTest);
	}
	printf("\n\nelements successfully added to the tree...\n\n");
	
	printf("-------------------------------------\nprinted preOrder after added elements\n-------------------------------------\n");
	printPreOrder(myTree->root, &printTest);
	printf("\n");

	printf("-------------------------------------\nprinted inOrder after added elements\n-------------------------------------\n");
	printInOrder(myTree->root, &printTest);
	printf("\n");

	h = height(myTree->root);

	printf("-------------------------------------\npretty print after added elements\n-------------------------------------\n");
	prettyPrint(h, myTree->root, &printTest);

	node = minValueNode(myTree->root);

	myTree->root = deleteNode(myTree->root, node->data, &compareTest);

	node = minValueNode(myTree->root);

	myTree->root = deleteNode(myTree->root, node->data, &compareTest);

	node = minValueNode(myTree->root);

	myTree->root = deleteNode(myTree->root, node->data, &compareTest);

	printf("\n\n5 elements successfully deleted, lowest first...\n\n");

	printf("--------------------------------\nprinted preOrder after 5 deletes\n--------------------------------\n");
	printPreOrder(myTree->root, &printTest);
	printf("\n");

	printf("--------------------------------\nprinted inOrder after 5 deletes\n--------------------------------\n");
	printInOrder(myTree->root, &printTest);
	printf("\n");

	h = height(myTree->root);

	printf("-------------------------------------\npretty print after 5 deleted elements\n------------------------------------\n");
	prettyPrint(h, myTree->root, &printTest);

	destroyTree(myTree);
	printf("\n\nall elements successfully destroyed...\n\n");

	return 0;
}