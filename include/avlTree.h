#ifndef BINTREE_GUARD
#define BINTREE_GUARD


#include "treeNode.h"


typedef struct avlTree
{
	struct treeNode * root;
	int (* compareptr) (void *, void *);
	void (* copyptr) (void *);
	void (* destroyptr) (void *);
}tree;


/************************
createTree

purpose: this function returns a pointer to a binary tree.
You must send pointers to the compare, copy and destroy functions when you create the tree.

preCondition: None.
postCondition: Tree is created and returned.
*********************/
tree * createTree(int (*compareptr) (void *, void *), void (* copyptr) (void *), void (* destroyptr) (void *));


/************************
height

purpose: this function finds the height of the tree.

preCondition: Tree exists.
postCondition: None.
*********************/
int height(treeNode *root);


/****************************
addToTree

purpose: this function adds the data item to the tree.
The item is added using the compare function.
If the data is a duplicate (as indicated by the compare function returning a zero) then the data will not be added to the tree.

preCondition: That a compare function exists and a tree exists.
postCondition: Tree has one more element and is re-balanced.
*******************************/
treeNode *addToTree(treeNode *root, void *data, int (*compare) (void *, void *));


/*******************************
printInOrder

purpose: This function prints the tree using an inOrder traversal.
preCondition: A tree exists.
postCondition: None.
*********************************/
void printInOrder(treeNode * root, void (*print)(void *data));


/*******************************
printPreOrder

purpose: This function prints the tree using a preOrder traversal.
preCondition: A tree exists.
postCondition: None.
*********************************/
void printPreOrder(treeNode *root, void (*print) (void *data));


/*******************************
prettyPrint

purpose: This function prints the tree using a inOrder traversal.
preCondition: A tree exists.
postCondition: None.
*********************************/
void prettyPrint(int height, treeNode *root, void (*print)(void *data));


/*******************************
minValueNone

purpose: This function finds the minimum value node of the tree.
preCondition: A tree exists.
postCondition: None.
*********************************/
treeNode * minValueNode(treeNode *node);


/*******************************
deleteNode

purpose: This function deletes the given node from the tree.
preCondition: A tree exists.
postCondition: Tree has one less element.
*********************************/
treeNode* deleteNode(treeNode *root, void *data, int (*compare) (void *, void *));

/*******************************
destroyTree

purpose: This function destroys the tree and frees memory.
preCondition: A tree exists.
postCondition: A tree is destroyed and no longer exists.
*********************************/
void destroyTree(tree *myTree);

#endif