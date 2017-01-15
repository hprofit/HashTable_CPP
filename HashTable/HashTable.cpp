#include "stdafx.h"
#include "HashTable.h"

template <typename KEY_TYPE, typename VALUE_TYPE>
int HashTable<KEY_TYPE, VALUE_TYPE>::getHashArrayIndex(KEY_TYPE key)
{
	std::size_t keyHash = std::hash<KEY_TYPE>{}(key);
	return keyHash % maxHashArraySize; 
}


template <typename KEY_TYPE, typename VALUE_TYPE>
void HashTable<KEY_TYPE, VALUE_TYPE>::addPair(KEY_TYPE key, VALUE_TYPE value)
{
	unsigned int hashArrayIndex = getHashArrayIndex(key);
	hashArray->at(hashArrayIndex)->addItem(value);
}

template <typename KEY_TYPE, typename VALUE_TYPE>
void HashTable<KEY_TYPE, VALUE_TYPE>::deletePair(KEY_TYPE key)
{
	unsigned int hashArrayIndex = getHashArrayIndex(key);
	hashArray->at(hashArrayIndex)->removeItem(key);
}

template <typename KEY_TYPE, typename VALUE_TYPE>
void HashTable<KEY_TYPE, VALUE_TYPE>::setValue(KEY_TYPE key, VALUE_TYPE value)
{

}

template <typename KEY_TYPE, typename VALUE_TYPE>
VALUE_TYPE HashTable<KEY_TYPE, VALUE_TYPE>::getValue(KEY_TYPE key)
{

}