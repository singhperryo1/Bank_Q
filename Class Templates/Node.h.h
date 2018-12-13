//header file for the template class Node

#ifndef _NODE
#define _NODE

template<class ItemType>
class Node
{
private:
	ItemType       item;
	Node<ItemType> *next;
public:
	Node();  //default constructor
	Node(const ItemType &anItem); //non default constructor #1
	Node(const ItemType &anItem, Node<ItemType> *nextPtr); //non default constructor #2
	void setItem(const ItemType &anItem);
	void setNext(Node<ItemType> *nextPtr);
	ItemType getItem() const;
	Node<ItemType> *getNext() const;
};
template<class ItemType>
Node<ItemType>::Node()
{
	next=NULL;
}

template<class ItemType>
Node<ItemType>::Node(const ItemType &anItem)
{
	item=anItem;
}

template<class ItemType>
Node<ItemType>::Node(const ItemType &anItem,Node<ItemType> *nextPtr)
{
	item=anItem;
	next=nextPtr;
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType &anItem)
{
	item=anItem;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType> *nextPtr)
{
	next=nextPtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
}
#endif