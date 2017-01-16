#pragma once

#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

#include <memory>

using std::unique_ptr;
using std::make_unique;

template <typename KEY_TYPE, typename VALUE_TYPE> class LinkedListNode
{
private:
	LinkedListNode<KEY_TYPE, VALUE_TYPE>* nextNode = NULL;
	std::unique_ptr<VALUE_TYPE> nodeValue;
	std::unique_ptr<KEY_TYPE> nodeKey;

public:
	LinkedListNode(KEY_TYPE key, VALUE_TYPE value)
	{
		nodeValue = std::make_unique<VALUE_TYPE>(value);
		nodeKey = std::make_unique<KEY_TYPE>(key);
	};

	~LinkedListNode()
	{
		if (nextNode != NULL)
		{
			delete nextNode;
		}
	};

	std::unique_ptr<VALUE_TYPE>& getValuePtr()
	{
		return nodeValue;
	};

	VALUE_TYPE getValue()
	{
		return *(nodeValue.get());
	};

	void setValue(VALUE_TYPE newValue)
	{
		nodeValue.reset();
		nodeValue = std::make_unique<VALUE_TYPE>(newValue);
	};

	std::unique_ptr<KEY_TYPE>& getKeyPtr()
	{
		return nodeKey;
	};

	KEY_TYPE getKey()
	{
		return *(nodeKey.get());
	};

	void setNextNode(LinkedListNode<KEY_TYPE, VALUE_TYPE>* newNextNode)
	{
		nextNode = newNextNode;
	};

	LinkedListNode<KEY_TYPE, VALUE_TYPE>* getNextNode()
	{
		return nextNode;
	};
};

#endif