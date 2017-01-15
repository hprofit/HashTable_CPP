#pragma once

#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

#include <memory>

template <typename TYPE> class LinkedListNode
{
private:
	LinkedListNode<TYPE>* nextNode;
	std::unique_ptr<TYPE> nodeValue;

public:
	LinkedListNode(TYPE value)
	{
		nodeValue = make_unique<TYPE>(value);
	}

	~LinkedListNode()
	{
		delete nextNode;
	}

	std::unique_ptr<TYPE>& getValuePtr();
	TYPE getValue();
	void setNextNode(LinkedListNode* newNextNode);
	LinkedListNode<TYPE>* getNextNode();
};

#endif