#pragma once

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <memory>
#include "linkedList.h"

template <typename KEY_TYPE, typename VALUE_TYPE> class HashTable
{
private:
	//unique_ptr< HashTable<string, int> > hash(HashTable<string, int>());
	std::vector< std::unique_ptr< LinkedList<VALUE_TYPE> > > hashArray;
	int maxDensity;
	int maxHashArraySize;

public:
	HashTable<KEY_TYPE, VALUE_TYPE>()
	{ };

	~HashTable<KEY_TYPE, VALUE_TYPE>()
	{ };


};
#endif