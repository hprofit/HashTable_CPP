#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "linkedListNode.h"

template <typename TYPE> class LinkedList
{
private:
	LinkedListNode<TYPE>* firstNode;

	void prependNode(LinkedListNode<TYPE>* newNode);

public:
	LinkedList<TYPE>()
	{ };

	~LinkedList<TYPE>()
	{
		delete firstNode;
	};

	void addItem(TYPE value);
	void removeItem();
	LinkedListNode<TYPE>* getFirstNode();
	LinkedListNode<TYPE>* findNodeWithValue(TYPE value);
};

#endif