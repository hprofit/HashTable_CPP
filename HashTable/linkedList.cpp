#include "stdafx.h"
#include "linkedList.h"

template <typename TYPE>
void LinkedList<TYPE>::prependNode(LinkedListNode<TYPE>* newNode) 
{
	newNode->setNextNode(firstNode);
	firstNode = newNode;
}


template <typename TYPE>
void LinkedList<TYPE>::addItem(TYPE value)
{
	LinkedListNode<TYPE> *node = new LinkedListNode<TYPE>(value);
	prependNode(node);
}

template <typename TYPE>
LinkedListNode<TYPE>* LinkedList<TYPE>::getFirstNode()
{
	return firstNode;
}

template <typename TYPE>
LinkedListNode<TYPE>* LinkedList<TYPE>::findNodeWithValue(TYPE value)
{
	LinkedListNode<TYPE>* currentNode = firstNode;

	while (true)
	{
		if (currentNode->getValue() == value)
		{
			return currentNode;
		}

		currentNode = currentNode->getNextNode();
		if (currentNode == NULL)
		{
			delete currentNode;
			break;
		}
	}

	return NULL;
}