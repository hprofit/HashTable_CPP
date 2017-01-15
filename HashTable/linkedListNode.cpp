#include "stdafx.h"
#include "linkedListNode.h"

using std::unique_ptr;
using std::make_unique;

template <typename TYPE> 
unique_ptr<TYPE>& LinkedListNode<TYPE>::getValuePtr()
{
	return nodeValue;
}

template <typename TYPE> 
TYPE LinkedListNode<TYPE>::getValue()
{
	return *(nodeValue.get());
}

template <typename TYPE> 
void LinkedListNode<TYPE>::setNextNode(LinkedListNode<TYPE>* newNextNode)
{
	nextNode = newNextNode;
}

template <typename TYPE> 
LinkedListNode<TYPE>* LinkedListNode<TYPE>::getNextNode()
{
	return nextNode;
}