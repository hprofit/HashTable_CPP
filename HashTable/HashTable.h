#pragma once

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <functional>
#include <vector>
#include <memory>
#include <cstddef>
#include "linkedList.h"

template <typename KEY_TYPE, typename VALUE_TYPE> class HashTable
{
private:
	std::vector< std::unique_ptr< LinkedList<KEY_TYPE, VALUE_TYPE> > > hashArray;
	int maxDensity = 5;
	int maxHashArraySize = 16;

	int getHashArrayIndex(KEY_TYPE key)
	{
		std::size_t keyHash = std::hash<KEY_TYPE>{}(key);
		return keyHash % maxHashArraySize;
	};

public:
	HashTable<KEY_TYPE, VALUE_TYPE>()
	{
		hashArray.resize(maxHashArraySize);
		for (int index = 0; index < maxHashArraySize; index++)
		{
			std::unique_ptr< LinkedList<KEY_TYPE, VALUE_TYPE> > newList(new LinkedList<KEY_TYPE, VALUE_TYPE>());
			hashArray.at(index) = std::move(newList);
		}
	};
	~HashTable<KEY_TYPE, VALUE_TYPE>()
	{ };

	void addPair(KEY_TYPE key, VALUE_TYPE value)
	{
		int hashArrayIndex = getHashArrayIndex(key);
		hashArray.at(hashArrayIndex)->addItem(key, value);
	};

	void deletePair(KEY_TYPE key)
	{
		int hashArrayIndex = getHashArrayIndex(key);
		hashArray.at(hashArrayIndex)->removeItem(key);
	};

	void setValue(KEY_TYPE key, VALUE_TYPE value)
	{
		int hashArrayIndex = getHashArrayIndex(key);
		LinkedListNode<KEY_TYPE, VALUE_TYPE>* node = hashArray.at(hashArrayIndex)->findItemWithKey(key);
		node->setValue(value);
	};

	VALUE_TYPE getValue(KEY_TYPE key)
	{
		int hashArrayIndex = getHashArrayIndex(key);
		LinkedListNode<KEY_TYPE, VALUE_TYPE>* node = hashArray.at(hashArrayIndex)->findItemWithKey(key);
		return node->getValue();
	};
};
#endif