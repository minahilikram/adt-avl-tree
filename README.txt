************
Compilation
************
	all :
		to compile all programs, open terminal type "make"

	todoListManager :
		open terminal type "make todoList"

	treeTests :
		open terminal type "make treeTesting"

	queueTests :
		open terminal type "make queueTesting"


***********************
Running the program(s)
***********************
	toDoListManager :
		open terminal type "make run" or type "./bin/groceries ./path/to/executable"

	treeTests :
		open terminal type "make runTreeTests" or type "./bin/treeTest"

	queueTest :
		open terminal type "make runQueueTests" or type "./bin/queueTest"


*****************
Known Limitations
*****************
	toDoListManager :
		doesn't check valgrind for memory leaks but attempted to destroy everything
		cannot remove if only one item in list
	
	tree :
		any known limitations with the tree are reported in "docs/treeTesting.txt"

	priorityQueue :
		any known limitations with the queue are reported in "docs/queueTesting.txt"


***********
References
***********
	http://www.geeksforgeeks.org/archives/18009
	http://www.dutky.info/jeff/software/searchtree/searchtree.c.html
	http://anoopsmohan.blogspot.ca/2011/11/avl-tree-implementation-in-c.html