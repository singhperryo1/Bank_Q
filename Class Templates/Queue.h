#ifndef _QUEUE
#define _QUEUE
#include "Node.h"
#include<iostream>
using namespace std;
template<class ItemType>
class Queue
{
private:
	Node<ItemType> *backPtr;
	Node<ItemType> *frontPtr;

public:
	Queue();  //Default constructor
	Queue(const Queue<ItemType> &aQueue); //Copy constructor

	bool isEmpty() const;
	bool enqueue(const ItemType &newEntry);
	bool dequeue();
	ItemType peekFront() const;
	void display();
};

template<class ItemType>
//Default Constructor:
Queue<ItemType>::Queue()
{
	backPtr = NULL;
	frontPtr = NULL;
}
//Copy Constructor:
template<class ItemType>
Queue<ItemType>::Queue(const Queue<ItemType>& aQueue)
{
	Node<ItemType> *originalNodePtr = aQueue.frontPtr;
	if (originalNodePtr == NULL) {
		frontPtr = NULL;
		backPtr = NULL;
	}
	else {
		//copy the first node
		frontPtr = new Node<ItemType>;
		frontPtr->setItem(originalNodePtr->getItem());
		//copy the remaining nodes
		backPtr = frontPtr;
		while (originalNodePtr->getNext() != NULL) {
			originalNodePtr = originalNodePtr->getNext();
			ItemType nextItem = originalNodePtr->getItem();
			Node<ItemType> *newNode = new Node<ItemType>(nextItem, NULL);
			backPtr->setNext(newNode);
			backPtr = backPtr->getNext();
		}
		backPtr->setNext(NULL);
	}
}
template<class ItemType>
bool Queue<ItemType>::isEmpty() const
{
	return (frontPtr == NULL);
}

template<class ItemType>
bool Queue<ItemType>::enqueue(const ItemType &newEntry)
{
	Node <ItemType> *jqueue = new Node<ItemType>(newEntry, NULL);
	if (isEmpty())
	{
		frontPtr = jqueue;
		backPtr = jqueue;
		return true;
	}
	else
	{
		backPtr->setNext(jqueue);
		backPtr = jqueue;
		return true;
	}
	return false;
}
template<class ItemType>
bool Queue<ItemType>::dequeue()
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		if (frontPtr = backPtr)
		{
			frontPtr = NULL;
			backPtr = NULL;
			delete(frontPtr);
			delete(backPtr);
			return true;
		}
		else
		{
			Node <ItemType> *del = frontPtr;
			del->setNext(NULL);
			frontPtr = frontPtr->getNext();
			delete(del);
			return true;
		}
	}
	return false;
}
template<class ItemType>
ItemType Queue<ItemType>::peekFront() const
{
	return (frontPtr->getItem());
}
template <class ItemType>
void Queue<ItemType>::display()
{
	Node<ItemType> *j = frontPtr;
	while (j != NULL)
	{
		cout << j->getItem();
		cout << endl;
		j = j->getNext();
	}
}
#endif
