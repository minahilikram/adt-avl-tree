/*****************************
References

    http://www.geeksforgeeks.org/archives/18009
    http://www.dutky.info/jeff/software/searchtree/searchtree.c.html
    http://anoopsmohan.blogspot.ca/2011/11/avl-tree-implementation-in-c.html
*****************************/

#include <stdio.h>
#include <stdlib.h>
#include "avlTree.h"


/********************
this function creates a binary tree and sets everything to NULL or the corresponding function.
*********************/
tree *createTree(int (*compare) (void *, void *), void (* copy) (void *), void (* destroy) (void *)) {
	tree * myTree;
	myTree = malloc(sizeof(tree));
	myTree->root = NULL;
	myTree->compareptr = compare;
	myTree->copyptr = copy;
	myTree->destroyptr = destroy;

	return myTree;
}


/********************
this function finds the height of the tree.
*********************/
int height(treeNode *root) {
	int leftHeight;
	int rightHeight;

   if (root == NULL) 
       return 0;

   else {
       leftHeight = height(root->left);
       rightHeight = height(root->right);
 
       if (leftHeight > rightHeight) 
           return(leftHeight + 1);

       else
       	return(rightHeight + 1);
   }
}


/********************
this function finds the height difference between the right and the left subtree.
*********************/
int heightDifference(treeNode *root) {
	int leftHeight;
	int rightHeight;
	int balanceFactor;

    leftHeight = height(root->left);
    rightHeight = height(root->right);
    balanceFactor = leftHeight - rightHeight;
    return balanceFactor;
}


/********************
this function rotates the two left subtrees to up and down.
*********************/
treeNode *leftLeftRotation(treeNode *root) {
    treeNode *node;
    node = root->left;
    root->left = node->right;
    node->right = root;
    return node;
}


/********************
this function rotates the two right subtrees to up and down.
*********************/
treeNode* rightRightRotation(treeNode *root) {
    treeNode *node;
    node = root->right;
    root->right = node->left;
    node->left= root;
    return node;
}


/********************
this function rotates the left and the right subtree to up and down.
*********************/
treeNode *leftRightRotation(treeNode *root) {
    treeNode *node;
    node = root->left;
    root->left = rightRightRotation(node);
    return leftLeftRotation(root);
}


/********************
this function rotates the right and the left subtree to up and down.
*********************/
treeNode* rightLeftRotation(treeNode *root) {
    treeNode *node;
    node = root->right;
    root->right = leftLeftRotation(node);
    return rightRightRotation(root);
}


/********************
this function balances the tree using the tree rotations where required.
*********************/
treeNode *balanceTree(treeNode *root) {

	int balanceFactor;

    balanceFactor = heightDifference(root);
    if (balanceFactor > 1) {
        if (heightDifference(root->left) > 0)
            root = leftLeftRotation(root);

        else
            root = leftRightRotation(root);
    }
    else if(balanceFactor < -1) {
        if(heightDifference(root->right) > 0)
            root = rightLeftRotation(root);

        else
            root = rightRightRotation(root);
    }
    return root;
}


/********************
this function adds data to the tree root and sets the left and right children to null.
*********************/
treeNode *addToTree(treeNode *root, void *data, int (*compare) (void *, void *)) {

	if (root == NULL) {
	    root = malloc(sizeof(treeNode));
	    root->data = data;
	    root->left = NULL;
	    root->right = NULL;
	    return root;
	}
	else if (compare(data, root->data) < 0) {
		root->left = addToTree(root->left, data, compare);
        root = balanceTree(root);
	}
	else if (compare(data, root->data) > 0) {
    	root->right = addToTree(root->right, data, compare);
    	root = balanceTree(root);
    }
	return root;
}


/********************
this function prints the tree in-order traversal.
*********************/
void printInOrder(treeNode * root, void (*print)(void *data)) {
    if(root == NULL)
        return;
    else {
         printInOrder(root->left, print);
         print(root->data);
         printInOrder(root->right, print);
    }
}


/********************
this function prints the tree pre-order traversal.
*********************/
void printPreOrder(treeNode *root, void (*print)(void *data)) {
    if(root == NULL)
        return;
    else {
        print(root->data);
        printPreOrder(root->left, print);
        printPreOrder(root->right, print);
    }
}



/********************
this function prints the tree pretty
*********************/
void prettyPrint(int height, treeNode *root, void (*print)(void *data)) {
    int i;
      
    if (root->left != NULL)
        prettyPrint(height+1, root->left, print);

    for (i=0; i<=height; i++) {
        if (height == 0) {
        printf("--");
        }
        else if (height != 0) {
            printf("      ");
        }
    }
    printf("|");
    print(root->data);
    
    if (root->right != NULL)
        prettyPrint(height+1, root->right, print);
}


/********************
this function finds the minimum node.
*********************/
treeNode * minValueNode(treeNode *node) {
    
    while (node->left != NULL)
        node = node->left;
 
    return node;
}


/********************
this function removes from tree.
*********************/
treeNode* deleteNode(treeNode *root, void *data, int (*compare) (void *, void *)) {
    treeNode *temp;
 
    if (root == NULL)
        return root;
 
    if (compare(data, root->data) < 0)
        root->left = deleteNode(root->left, data, compare);
 
    else if(compare(data, root->data) > 0)
        root->right = deleteNode(root->right, data, compare);
 
    else {
        if((root->left == NULL) || (root->right == NULL)) {
            
            if (root->left != NULL)
                temp = root->left;

            else
                temp = root->right;

            if(temp == NULL) {
                temp = root;
                root = NULL;
            }

            else
             *root = *temp;
 
            free(temp);
        }
        else {
            temp = minValueNode(root->right);

            root->data = temp->data;
 
            root->right = deleteNode(root->right, temp->data, compare);
        }
    }
 
    return root;
}


/********************
this function destroys the tree.
*********************/
void destroyTree(tree *myTree) {
    treeNode *node;

    while(myTree->root != NULL) {
        node = minValueNode(myTree->root);
        myTree->root = deleteNode(myTree->root, node->data, myTree->compareptr);
    }

    free(myTree);
}