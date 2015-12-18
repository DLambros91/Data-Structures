/**
 * 	Name: Demetrios Lambropoulos
 */

#ifndef DOUBLY_LIST_H
#define DOUBLY_LIST_H

/**
 * doubly-list.h
 */

#include <stdlib.h>

struct Nodes
{
	void * data;
	void * next;
	void * prev;
	int numRef;
};
typedef struct Nodes* Node;

struct DoublyList
{
	int manyItems;
	Node head;
};

typedef struct DoublyList * DoublyListPtr;

/*
 *  Iterator type for user to "walk" through the list item by item, from
 *  beginning to end.
 */
struct DoublyListIterator
{
	Node iterator;
	DoublyListPtr dl;
};
typedef struct DoublyListIterator * DoublyListIteratorPtr;

/*
 * DLCreate creates a new, empty doubly linked list.
 *
 * If the function succeeds, it returns a (non-NULL) DoublyListT object, 
 * otherwise, it returns NULL.
 */

DoublyListPtr DLCreate();

/*
 * DLDestroy destroys a list, freeing all dynamically allocated memory.
 */

void DLDestroy(DoublyListPtr list);

int addNode(DoublyListPtr list, Node head, Node n);

/*
 * DLInsert inserts a given object into a doubly linked list. 
 *
 * If the function succeeds, it returns 1, otherwise it returns 0.
 */

int DLInsert(DoublyListPtr list, void * newObj);

/*
 * DLRemove removes a given object from a doubly linked list. DLRemove 
 * may not change the object whose pointer is passed as the second 
 * argument. This allows you to pass a pointer to a temp object equal to 
 * the object in the doubly linked list you want to remove.
 *
 * If the function succeeds, it return 1, otherwise it returns 0.
 */

int DLRemove(DoublyListPtr list, void * newObj);

/*
 * DLCreateIterator creates an iterator object that will allow the caller
 * to "walk" through the list from beginning to the end using DLNextItem.
 *
 * If the function succeeds, it returns a non-NULL pointer to a 
 * DoublyListIterT object, otherwise it returns NULL. The DoublyListT
 * object should point to the first item in the doubly list, if the 
 * doubly list is not empty. If the doubly linked list object is empty, 
 * then the iterator should have a null pointer.
 */

DoublyListIteratorPtr DLCreateIterator(DoublyListPtr list);

/*
 * DLDestroyIterator destroys an iterator object that was created 
 * using DLCreateIterator(). Note that this function should destroy the 
 * iterator but should NOT affect the original list used to create the 
 * iterator in any way.
 */

void DLDestroyIterator(DoublyListIteratorPtr iter);

/*
 * DLGetItem returns the pointer to the data associated with the 
 * DoublyListIteratorPtr. It should return 0 if the iterator advanced past
 * the end of the doubly linked list.
 */

void * DLGetItem(DoublyListIteratorPtr iter);

/*
 * DLNextItem returns the pointer to the data associated with the next
 * object in the list encapsulated by the given iterator.
 * It should return a NULL when the end of the list has been reached.
 */

void * DLNextItem(DoublyListIteratorPtr iter);

void PrintList(SortedListPtr list);

#endif
