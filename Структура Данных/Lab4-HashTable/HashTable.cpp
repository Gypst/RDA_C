#include "HashTable.h"
#include "Dictionary.h"

Node::~Node()
{
	if (NextNode == nullptr)
	{
		delete[] NextNode;
	}
	else
	{
		NextNode->PrevNode = PrevNode;
	}

	if (PrevNode == nullptr)
	{
		delete[] PrevNode;
	}
	else
	{
		PrevNode->NextNode = NextNode;
	}
}

List::~List()
{
	delete[] Head;
}

HashTable::~HashTable()
{
	delete[] List;
}

bool AddWordToHashTable(HashTable* table, string key, string value)
{
	int hashIndex = HashFunc(key, table);
	if ((SameKeyCheck(&table->List[hashIndex], key) == true)
		&& (SameValCheck(&table->List[hashIndex], value) == true))
	{
		return false;
	}
	else
	{
		AddNewNode(&table->List[hashIndex], key, value);
		table->CountElem++;
		return true;
	}

}

int HashFunc(string keyWord, HashTable* hashTable)
{
	int hashIndex;
	hashIndex = 0;

	for (int i = 0; i < keyWord.length(); i++)
	{
		hashIndex = (hashIndex * HashConst + keyWord[i]) % hashTable->Capacity;
	}
	return hashIndex;
}

HashTable* InitHashTable(int capacity)
{
	HashTable* hashTable = new HashTable;
	hashTable->Capacity = capacity;
	hashTable->List = new List[capacity];
	hashTable->CountElem = 0;
	return hashTable;
}

void AddNewNode(List* list, string key, string value)
{
	Node* newNode = new Node;
	newNode->Key = key;
	newNode->Value = value;

	if (list->Length == 0)
	{
		list->Head = newNode;
	}
	else
	{	
		Node* lastNode = list->Head;
		while (lastNode->NextNode != nullptr)
		{
			lastNode = lastNode->NextNode;
		}

		lastNode->NextNode = newNode;
		newNode->PrevNode =lastNode;
	}
	list->Length++;
}

void DeleteNode(List* list, string key)
{
	if (list->Length != 0)
	{
		Node* headNode = list->Head;
		while (headNode->Key != key)
		{
			headNode = headNode->NextNode;
		}
		
		if (headNode->Key == key)
		{
			//midle 
			if ((headNode->PrevNode != nullptr) && (headNode->NextNode != nullptr))
			{
				headNode->PrevNode->NextNode = headNode->NextNode;
				headNode->NextNode->PrevNode = headNode->PrevNode;
			}
			//head and next exist
			else if ((headNode->PrevNode == nullptr) && (headNode->NextNode != nullptr))
			{
				headNode->NextNode->PrevNode = nullptr;
				list->Head = headNode->NextNode;
			}
			//exist only head
			else if ((headNode->PrevNode == nullptr) && (headNode->NextNode == nullptr))
			{
				list->Head = nullptr;
			}
			//tail
			else if ((headNode->PrevNode != nullptr) && (headNode->NextNode == nullptr))
			{
				headNode->PrevNode->NextNode = nullptr;
			}

			list->Length--;
			delete headNode;
		}
	}
}

void DeleteNodeVal(List* list, string val)
{
	Node* supNode = list->Head;

	if (list->Length != 0)
	{
		while (supNode->Value != val)
		{
			supNode = supNode->NextNode;
		}

		if (supNode->Value == val)
		{
			//midle 
			if ((supNode->PrevNode != nullptr) && (supNode->NextNode != nullptr))
			{
				supNode->PrevNode->NextNode = supNode->NextNode;
				supNode->NextNode->PrevNode = supNode->PrevNode;
			}
			//head and next exist
			else if ((supNode->PrevNode == nullptr) && (supNode->NextNode != nullptr))
			{
				supNode->NextNode->PrevNode = nullptr;
				list->Head = supNode->NextNode;
			}
			//exist only head
			else if ((supNode->PrevNode == nullptr) && (supNode->NextNode == nullptr))
			{
				list->Head = nullptr;
			}
			//tail
			else if ((supNode->PrevNode != nullptr) && (supNode->NextNode == nullptr))
			{
				supNode->PrevNode->NextNode = nullptr;
			}

			list->Length--;
			delete supNode;
		}
	}
}

bool SameKeyCheck(List* list, string key)
{
	Node* tempNode = list->Head;

	while (tempNode != nullptr)
	{
		if (tempNode->Key == key)
		{
			return true;
		}
		tempNode = tempNode->NextNode;
	}
	return false;
}

bool SameValCheck(List* list, string val)
{
	Node* tempNode = list->Head;

	while (tempNode != nullptr)
	{
		if (tempNode->Value == val)
		{
			return true;
		}
		tempNode = tempNode->NextNode;
	}
	return false;
}

Node* Search(string key, HashTable* table)
{
	List* list = &table->List[HashFunc(key, table)];
	Node* tempNode = list->Head;

	if (list->Length != 0)
	{
		while (tempNode != nullptr)
		{
			if (key == tempNode->Key)
			{
				return tempNode;
			}
			else
			{
				tempNode = tempNode->NextNode;
			}
		}
	}
	return nullptr;
}

HashTable* ReHash(HashTable* table)
{
	int newsize = table->Capacity * NewSizeRate;
	HashTable* newTable = InitHashTable(newsize);
	newTable->CountElem = table->CountElem;
	int hashIndex = 0;
	Node* tempNode;
	for (int i = 0; i < table->Capacity; i++)
	{
		if (table->List[i].Head != nullptr)
		{
			tempNode = table->List[i].Head;
			while (tempNode != nullptr)
			{
				hashIndex = HashFunc(tempNode->Key, newTable);
				AddNewNode(&newTable->List[hashIndex], tempNode->Key, tempNode->Value);
				tempNode = tempNode->NextNode;
			}
		}
	}
	return newTable;
}