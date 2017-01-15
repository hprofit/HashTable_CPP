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
	std::vector< std::unique_ptr< LinkedList<VALUE_TYPE> > > hashArray;
	int maxDensity = 5;
	int maxHashArraySize = 16;

	int getHashArrayIndex(KEY_TYPE key);

public:
	HashTable<KEY_TYPE, VALUE_TYPE>()
	{
		hashArray.resize(maxHashArraySize);
	};
	~HashTable<KEY_TYPE, VALUE_TYPE>()
	{ };

	void addPair(KEY_TYPE key, VALUE_TYPE value);
	void deletePair(KEY_TYPE key);
	void setValue(KEY_TYPE key, VALUE_TYPE value);
	VALUE_TYPE getValue(KEY_TYPE key);
};
#endif