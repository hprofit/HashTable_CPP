#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>
#include <iostream>
#include "linkedListNode.h"

template <typename KEY_TYPE, typename VALUE_TYPE> class LinkedList
{
private:
	LinkedListNode<KEY_TYPE, VALUE_TYPE>* firstNode = NULL;
	unsigned int currentLength = 0;

	int getIndexOfNodeWithValue(VALUE_TYPE value)
	{
		LinkedListNode<KEY_TYPE, VALUE_TYPE>* currentNode = firstNode;
		int index = 0;

		while (true)
		{
			if (currentNode->getValue() == value)
			{
				return index;
			}

			index++;
			currentNode = currentNode->getNextNode();
			if (currentNode == NULL)
			{
				delete currentNode;
				break;
			}
		}

		return -1;
	}

	int getIndexOfNodeWithKey(KEY_TYPE key)
	{
		LinkedListNode<KEY_TYPE, VALUE_TYPE>* currentNode = firstNode;
		int index = 0;

		while (true)
		{
			if (currentNode->getKey() == key)
			{
				return index;
			}

			index++;
			currentNode = currentNode->getNextNode();
			if (currentNode == NULL)
			{
				delete currentNode;
				break;
			}
		}

		return -1;
	}

	void removeNodeAtIndex(int index)
	{
		// Node not found
		if (index == -1)
		{
			return;
		}
		// Node is first item in linked list
		else if (index == 0)
		{
			LinkedListNode<KEY_TYPE, VALUE_TYPE>* tmpNode = firstNode->getNextNode();
			firstNode->setNextNode(NULL);
			delete firstNode;
			firstNode = tmpNode;
		}
		// Node is elsewhere in the list
		else
		{
			LinkedListNode<KEY_TYPE, VALUE_TYPE>* prevNode = getItemAtIndex(index - 1);
			LinkedListNode<KEY_TYPE, VALUE_TYPE>* node = getItemAtIndex(index);
			if (prevNode != NULL && node != NULL)
			{
				prevNode->setNextNode(node->getNextNode());
				node->setNextNode(NULL);
				delete node;
			}
		}
		currentLength--;
	}

public:
	LinkedList<KEY_TYPE, VALUE_TYPE>()
	{ };

	~LinkedList<KEY_TYPE, VALUE_TYPE>()
	{
		if (firstNode != NULL)
		{
			delete firstNode;
		}
	};

	unsigned int length()
	{
		return currentLength;
	};

	void addItem(KEY_TYPE key, VALUE_TYPE value)
	{
		LinkedListNode<KEY_TYPE, VALUE_TYPE>* newNode = new LinkedListNode<KEY_TYPE, VALUE_TYPE>(key, value);
		
		newNode->setNextNode(firstNode);
		firstNode = newNode;

		currentLength++;
	};

	void removeItemByValue(VALUE_TYPE value)
	{
		int indexOfNode = getIndexOfNodeWithValue(value);
		removeNodeAtIndex(indexOfNode);
	};

	void removeItemByKey(KEY_TYPE key)
	{
		int indexOfNode = getIndexOfNodeWithKey(key);
		removeNodeAtIndex(indexOfNode);
	};

	LinkedListNode<KEY_TYPE, VALUE_TYPE>* getFirstNode()
	{
		return firstNode;
	};

	LinkedListNode<KEY_TYPE, VALUE_TYPE>* findItemWithValue(VALUE_TYPE value)
	{
		LinkedListNode<KEY_TYPE, VALUE_TYPE>* currentNode = firstNode;

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
	};

	LinkedListNode<KEY_TYPE, VALUE_TYPE>* findItemWithKey(KEY_TYPE key)
	{
		LinkedListNode<KEY_TYPE, VALUE_TYPE>* currentNode = firstNode;

		while (true)
		{
			if (currentNode == NULL)
			{
				delete currentNode;
				break;
			}

			if (currentNode->getKey() == key)
			{
				return currentNode;
			}

			currentNode = currentNode->getNextNode();
		}

		return NULL;
	};

	LinkedListNode<KEY_TYPE, VALUE_TYPE>* getItemAtIndex(int index)
	{
		if (index >= currentLength)
		{
			throw std::out_of_range("Index exceeded end of list.");
		}

		LinkedListNode<TYPE>* currentNode = firstNode;
		int curIndex = 0;

		while (curIndex != index)
		{
			currentNode = currentNode->getNextNode();
			if (currentNode == NULL)
			{
				delete currentNode;
				throw std::out_of_range("Index exceeded end of list or possible broken nextNode pointer.");
			}
			curIndex++;
		}

		return currentNode;
	};

	void printList()
	{
		LinkedListNode<KEY_TYPE, VALUE_TYPE>* currentNode = firstNode;
		while (true)
		{
			if (currentNode == NULL)
			{
				delete currentNode;
				break;
			}
			std::cout << "Key: " << currentNode->getKey() << " Value: " << currentNode->getValue() << std::endl;
			currentNode = currentNode->getNextNode();
		}
	};
};

#endif