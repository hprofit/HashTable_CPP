// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "linkedList.h"
#include "HashTable.h"

using std::unique_ptr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	vector<string> keys = { "First", "Second", "Third", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten" };
	unique_ptr< HashTable<int, string> > hash(new HashTable<int, string>());

	for (int idx = 1; idx < 11; idx++)
	{
		hash->addPair(idx, keys.at(idx - 1));
	}
	cout << hash->getValue(4) << endl;
	cout << hash->getValue(11) << endl;



	unique_ptr< HashTable<int, int> > intHash(new HashTable<int, int>());

	for (int idx = 1; idx < 32768; idx++)
	{
		intHash->addPair(idx, idx);
	}
	cout << "4: " << intHash->getValue(4) << endl;
	cout << "999: " << intHash->getValue(999) << endl;
	cout << "998 - Before Removal: " << intHash->getValue(998) << endl;
	intHash->deletePair(998);
	cout << "998 - After Removal: " << intHash->getValue(998) << endl;

	cout << "997 - Before Change: " << intHash->getValue(997) << endl;
	intHash->setValue(997, 1001);
	cout << "997 - After Change: " << intHash->getValue(997) << endl;

	cout << "1000: " << intHash->getValue(1000) << endl;


	unique_ptr< LinkedList<string, int> > linkedList(new LinkedList<string, int>());

	for (int idx = 0; idx < 10; idx++)
	{
		linkedList->addItem(std::to_string(idx), idx);
	}

	linkedList->printList();

	cout << "Press Any Key To Continue..." << endl;
	std::cin.ignore();

    return 0;
}

