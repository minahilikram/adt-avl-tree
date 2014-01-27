CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall -ansi -pedantic -g

#Directories where the compiler can find things
INCLUDES    = -Iinclude

all : todoList treeTesting queueTesting

todoList: 
	gcc $(CFLAGS) src/avlTree.c src/todoList.c src/main.c src/priorityQueue.c -o bin/assignmentThree -Iinclude

treeTesting:
	gcc $(CFLAGS) src/avlTree.c src/todoList.c src/treeTest.c -o bin/treeTest -Iinclude

queueTesting:
	gcc $(CFLAGS) src/avlTree.c src/todoList.c src/priorityQueue.c src/queueTest.c -o bin/queueTest -Iinclude

clean:
	@ rm *.o
	@ rm bin/*

run:
	./bin/groceries ./groceries.txt

runTreeTest:
	cd bin; ./treeTest

runQueueTest:
	cd bin; ./queueTest