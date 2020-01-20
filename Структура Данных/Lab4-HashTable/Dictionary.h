#pragma once
#include "HashTable.h"
#include <iostream>
#include <string>
#include "GetInt.h"
using namespace std;
const int DictConst = 25;

struct Dictionary
{
	HashTable* Table;

	~Dictionary();
};

bool AddWordToDic(Dictionary* dictionary, string key, string value);
Node* Search(Dictionary* dictionary, string key);
void DeleteNode(Dictionary* dictionary, string key);