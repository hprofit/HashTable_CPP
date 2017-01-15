// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include <string>
#include "HashTable.h"

using std::unique_ptr;
using std::cout;
using std::endl;
using std::string;

int main()
{
	unique_ptr< HashTable<string, int> > hash(new HashTable<string, int>());


    return 0;
}

