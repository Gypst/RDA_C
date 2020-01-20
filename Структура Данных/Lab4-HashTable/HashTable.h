#pragma once
#include <string>
using namespace std;

const int HashConst = 8;
const double OccupancyRate = 0.8;
const double NewSizeRate = 1.6;

struct Node
{
	string Key;
	string Value;
	Node* NextNode = nullptr;
	Node* PrevNode = nullptr;

	~Node();
};

struct List
{
	Node* Head = nullptr;
	int Length = 0;

	~List();
};

struct HashTable
{
	List* List;
	int Capacity;
	int CountElem;

	~HashTable();
};

int HashFunc(string inputWord, HashTable* hashTable);
HashTable* InitHashTable(int capacity);
HashTable* ReHash(HashTable* table);
void AddNewNode(List* list, string key, string value);
void DeleteNode(List* list, string key);
void DeleteNodeVal(List* list, string val);
bool SameKeyCheck(List* list, string key);
bool SameValCheck(List* list, string val);
Node* Search(string key, HashTable* table);
bool AddWordToHashTable(HashTable* table, string key, string value);