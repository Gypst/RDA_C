#pragma once
#include "Dictionary.h"
#include "HashTable.h"

bool AddWordToDic(Dictionary* dictionary, string key, string value)
{
	int hashIndex = HashFunc(key, dictionary->Table);

	if (SameKeyCheck(&dictionary->Table->List[hashIndex], key) == false)
	{
		AddNewNode(&dictionary->Table->List[hashIndex], key, value);
		dictionary->Table->CountElem++;
		return true;
	}

	return false;
}

Node* Search(Dictionary* dictionary, string key)
{
	List* list = &dictionary->Table->List[HashFunc(key, dictionary->Table)];
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

void DeleteNode(Dictionary* dictionary, string key)
{
	Node* findedNode = Search(dictionary, key);
	if (findedNode != nullptr)
	{
		//midle 
		if ((findedNode->PrevNode != nullptr) && (findedNode->NextNode != nullptr))
		{
			findedNode->PrevNode->NextNode = findedNode->NextNode;
			findedNode->NextNode->PrevNode = findedNode->PrevNode;
		}
		//head and next exist
		else if ((findedNode->PrevNode == nullptr) && (findedNode->NextNode != nullptr))
		{
			findedNode->NextNode->PrevNode = nullptr;
			dictionary->Table->List[HashFunc(key,dictionary->Table)].Head = findedNode->NextNode;
		}
		//exist only head
		else if ((findedNode->PrevNode == nullptr) && (findedNode->NextNode == nullptr))
		{
			dictionary->Table->List[HashFunc(key, dictionary->Table)].Head = nullptr;
		}
		//tail
		else if ((findedNode->PrevNode != nullptr) && (findedNode->NextNode == nullptr))
		{
			findedNode->PrevNode->NextNode = nullptr;
		}

		dictionary->Table->CountElem--;
		delete findedNode;
	}
}

Dictionary::~Dictionary()
{
	delete[] Table;
}