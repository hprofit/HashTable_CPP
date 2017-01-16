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

