//Header File for Class Template List

#ifndef _LIST
#define _LIST

#include"Node.h"

template<class ItemType>
class List
{
private:
	Node<ItemType> *head;
	int itemCount;                //Current count of list items
	Node<ItemType> *getNodeAt(int position) const;      //Return a pointer that hold the address of the node at 'position'
	Node<ItemType> *getNodeBefore(const ItemType &anEntry)const;
public:
	List(); //Default constructor
	bool isEmpty() const;  //Check if the list empty (no item stored in the list)
	int getLength() const; //Returns the number of items in the list
	bool insert(int position, const ItemType &newEntry); //Add a new entry to the list in a given position
	void displayList();
	bool remove(int position); //Remove an entry at given position from the list
	void clear(); //remove all the items from the list
	ItemType getEntry(int position) const; //Retrieves an item on the list at the given position
	void setEntry(int position, const ItemType &newEntry); //Change(replace) the item in an entry at given position
	void insertSorted(const ItemType &newEntry);
	bool removeSorted(const ItemType &anEntry);
	int getPosition(const ItemType &newEntry) const;
	int frequenceOf(ItemType anItem);
};

template<class ItemType>
List<ItemType>::List() 
{
	head = NULL;
	itemCount = 0;
}
template<class ItemType>
Node<ItemType> *List<ItemType>::getNodeAt(int position) const
{
	if (position<1 || position>itemCount) {
		cout << "Invalid position for function: getNode()\n";
		cout<<"Program aborted!\n";
		system("pause");
		exit(1);
	}
	Node<ItemType> *nodePtr = head;
	for (int i = 1; i<position; i++)
		nodePtr = nodePtr->getNext();
	return nodePtr;
}

template<class ItemType>
bool List<ItemType>::isEmpty() const
{
	return (head == NULL);
}

template<class ItemType>
int List<ItemType>::getLength() const
{
	return itemCount;
}

template<class ItemType>
bool List<ItemType>::insert(int position, const ItemType &newEntry)
{
	bool ableToInsert = (position >= 1) && (position <= itemCount + 1);
	if (ableToInsert) {
		if (position == 1) {
			//Add the new node to the beginning of the list
			head = new Node<ItemType>(newEntry,head);
		}
		else {
			//Find a pointers that point to the node at the position and the node before it
			Node<ItemType> *preNode, *currentNode;
			preNode = getNodeAt(position - 1);
			currentNode = preNode->getNext(); //Do not use "currentNode=getNode(position);" //Because it will equal to itemCount + 1
			//Insert the new node
			currentNode = new Node<ItemType>(newEntry, currentNode);
			preNode->setNext(currentNode);
		}
		itemCount++;
	}
	if (!ableToInsert) {
		cout << "Warning: Invalid position!\n";
		cout << "Warning: Insertion failed!\n";
	}
	return ableToInsert;
}

template<class ItemType>
void List<ItemType>::displayList()
{
	Node<ItemType> *currentNode = head;
	while(currentNode != NULL){
		cout<<currentNode->getItem() << endl;
		currentNode = currentNode->getNext();
	}
}

template<class ItemType>
bool List<ItemType>::remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= itemCount);
		if(ableToRemove){
			if(position == 1){
				Node<ItemType> *currentNode = head;
				head = currentNode->getNext();
				currentNode->setNext(NULL);
				delete(currentNode);
			}

			else{
				Node<ItemType> *preNode, *currentNode;
				preNode = getNodeAt(position - 1);
				currentNode = getNodeAt(position); //We can use getNodeAt because we aren't inserting a new node
				preNode->setNext(currentNode->getNext());
				currentNode->setNext(NULL);
				delete(currentNode);
			}
			itemCount--;
		}
		
		if(!ableToRemove){
			cout<<"Error removal failed."<<endl;
		}
	return ableToRemove;
}

template<class ItemType>
void List<ItemType>::clear()
{
	while(!isEmpty()){
		remove(1);
	}
	cout<<"The list has been cleared."<<endl;
}

template<class ItemType>
ItemType List<ItemType>::getEntry(int position) const
{
	Node<ItemType> *curPtr = getNodeAt(position);
	return (curPtr->getItem());
}

template<class ItemType>
void List<ItemType>::setEntry(int position, const ItemType &newEntry)
{
	Node<ItemType> *curPtr = getNodeAt(position);
	curPtr->setItem(newEntry);
}

template<class ItemType>
Node<ItemType> *List<ItemType>::getNodeBefore(const ItemType &anEntry)const
{
	if(isEmpty()){
		return NULL;
	}
	else{
		Node<ItemType> *currentNode = head, *preNode = currentNode;
		if(currentNode->getItem() >= anEntry) //Checking for the first one in case that is the first number that is greater or equal to
			return NULL;
		else{
			preNode = currentNode;
			currentNode = currentNode->getNext(); //So it can be one node ahead of the preNode
			while(currentNode != NULL){
				if(currentNode->getItem() >= anEntry){
					return  preNode;
					//break;
				}
				else{
					preNode = currentNode;
					currentNode = currentNode->getNext();
				}
			}
			return preNode; //Once we reached the end of NULL
		}
	}
}

template <class ItemType>
void List<ItemType>::insertSorted(const ItemType &newEntry)
{

	Node<ItemType> *currentNode = head;
	if (isEmpty() || getNodeBefore(newEntry) == NULL)
		head = new Node<ItemType>(newEntry, head);
	
	else {
		Node<ItemType> *preNode = getNodeBefore(newEntry);
		currentNode = preNode->getNext();
		currentNode = new Node<ItemType>(newEntry, currentNode);
		preNode->setNext(currentNode);
	}
	itemCount++;
}

template <class ItemType>
bool List<ItemType>::removeSorted(const ItemType &anEntry)
{
	if(isEmpty()){
		cout<<"Removal Failed!!"<<endl;
		return false;
	}
	else{
		Node<ItemType> *preNode = getNodeBefore(anEntry);
		Node<ItemType> *currentNode = preNode->getNext();

		if(preNode == NULL)
			preNode = head;
			if(preNode->getItem() > anEntry){
				cout<<"Removal Failed"<<endl;
				return false;
			}
			else if(preNode->getItem() == anEntry){
				head = preNode->getNext();
				preNode->setNext(NULL);
				delete(preNode);
				itemCount--;
				return true;
			}
		else{
			if(currentNode != NULL){
				if(currentNode->getItem() > anEntry){
					cout<<"That number is not contained in the list."<<endl;
					cout<<endl;
					return false;
				}
				else{
					preNode = getNodeBefore(anEntry);
					preNode->setNext(currentNode->getNext());
					currentNode->setNext(NULL);
					delete(currentNode);
					itemCount--;
					return true;
				}
			}
			else{
				cout<<"That number is not contained in the list."<<endl;
				cout<<endl;
				return false;
			}
		}
	}
}
template <class ItemType>
int List<ItemType>::getPosition(const ItemType &newEntry) const
{
	int position = 1;
	Node<ItemType> *currentNode = head;

	if(isEmpty() || currentNode->getItem() >= newEntry)
		position = 1;

	while(currentNode != NULL && currentNode->getItem() < newEntry){
			currentNode = currentNode->getNext();
			position++;
	}
	return position;
}
template <class ItemType>
int List<ItemType>::frequenceOf(ItemType anItem)
{
	int counter = 0;
	Node<ItemType> *currentNode = head;
	while(currentNode != NULL){
		if(currentNode->getItem() == anItem){
			counter++;
		}
		currentNode = currentNode->getNext();
	}
	return counter;
}

#endif