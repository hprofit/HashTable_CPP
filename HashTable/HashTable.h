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
	const unsigned int maxDensity = 5;
	const unsigned int maxHashArraySize = 16;

	int getHashArrayIndex(KEY_TYPE key)
	{
		std::size_t keyHash = std::hash<KEY_TYPE>{}(key);
		return keyHash % maxHashArraySize;
	};

	void rehash()
	{
		// Resize the vector to the previous size + max size
		hashArray.resize(hashArray.size() + maxHashArraySize);
		// Calculate the previous size. Note it can NOT be negative.
		unsigned int oldSize = static_cast<unsigned int>(hashArray.size()) - maxHashArraySize;
		unsigned int currentMaxSize = static_cast<unsigned int>(hashArray.size());

		// Inititalize all items in the array
		for (unsigned int index = oldSize; index < currentMaxSize; index++)
		{
			std::unique_ptr< LinkedList<KEY_TYPE, VALUE_TYPE> > newList(new LinkedList<KEY_TYPE, VALUE_TYPE>());
			hashArray.at(index) = std::move(newList);
		}
	};

public:
	HashTable<KEY_TYPE, VALUE_TYPE>()
	{
		rehash();
	};
	~HashTable<KEY_TYPE, VALUE_TYPE>()
	{ };

	void addPair(KEY_TYPE key, VALUE_TYPE value)
	{
		int hashArrayIndex = getHashArrayIndex(key);
		bool placed = false;

		while (!placed)
		{
			// If the current linked list is defined and shorter than the max depth size, 
			// add to that linked list and set placed to true
			if (hashArray.at(hashArrayIndex) != NULL && hashArray.at(hashArrayIndex)->length() < maxDensity)
			{
				hashArray.at(hashArrayIndex)->addItem(key, value);
				placed = true;
			}
			else
			{
				// If the current linked list is not defined, define it, add to it, and set placed to true
				if (hashArray.at(hashArrayIndex) == NULL)
				{
					std::unique_ptr< LinkedList<KEY_TYPE, VALUE_TYPE> > newList(new LinkedList<KEY_TYPE, VALUE_TYPE>());
					hashArray.at(hashArrayIndex) = std::move(newList);

					hashArray.at(hashArrayIndex)->addItem(key, value);
					placed = true;
				}
				// If the current linked list's length meets the max density allowed, 
				// increment hashArrayIndex by the maxHashArraySize to check the next list
				else if (hashArray.at(hashArrayIndex)->length() == maxDensity)
				{
					hashArrayIndex += maxHashArraySize;

					// If the new hashArrayIndex is out of range of the current hashArray, 
					// rehash before restarting loop
					if (hashArrayIndex > hashArray.size())
					{
						rehash();
					}
				}
			}
		}
	};

	bool isKeyInLinkedList(int index, KEY_TYPE key)
	{
		LinkedListNode<KEY_TYPE, VALUE_TYPE>* node = hashArray.at(index)->findItemWithKey(key);
		return node != NULL;
	}

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
		bool found = false;
		VALUE_TYPE val = VALUE_TYPE();

		while (!found)
		{
			if (!isKeyInLinkedList(hashArrayIndex, key))
			{
				hashArrayIndex += maxHashArraySize;
				// We've reached the end of the hashArray, return default value
				if (hashArrayIndex >= hashArray.size())
				{
					found = true;
				}
			}
			else
			{
				// Value exists in the linkedList at the given hashArrayIndex,
				// grab the value and set found to true
				val = hashArray.at(hashArrayIndex)->findItemWithKey(key)->getValue();
				found = true;
			}
		}

		return val;
	};
};
#endif