#include "HashTableMenu.h"

void ShowTable(HashTable* table)
{
	Node* tempNode;
	cout << "Hash table: " << endl;

	for (int i = 0; i < table->Capacity; i++)
	{
		if (table->List[i].Length != 0)
		{
			tempNode = table->List[i].Head;
			cout << "[" << i << "] ";
			while (tempNode != nullptr)
			{
				cout << " | ";
				if (tempNode->Key.length() != 0 && tempNode->Value.length() != 0)
				{
					cout << tempNode->Key << '\t' << tempNode->Value << " ";
				}
				tempNode = tempNode->NextNode;

			}
			cout << endl;
		}
		else
		{
			cout << "[" << i << "] " << "Empty node" << endl;
		}

	}
}

void HashMenu()
{
	bool hashCreated = false;
	HashTable* hashTable = nullptr;
	List* tempList = nullptr;

	while (true)
	{
		std::system("CLS");

		if (hashCreated)
		{
			ShowTable(hashTable);
		}

		cout << "Menu of hash table:" << endl
			<< "1. Add key with value" << endl
			<< "2. Delete with key" << endl
			<< "3. Search with key" << endl
			<< "0. Exit" << endl;
		int userAnswer = GetInt();

		switch (userAnswer)
		{
		case 1:
		{
			cout << "Enter keyWord: " << endl;
			string userAnswKey;
			cin >> userAnswKey;
			cin.ignore(132, '\n');
			cout << "Enter value for the keyWord: " << endl;
			string userAnswVal;
			getline(cin, userAnswVal);

			if (hashCreated)
			{
				int occupancy = hashTable->CountElem;
				if (occupancy >= OccupancyRate * hashTable->Capacity)
				{
					hashTable = ReHash(hashTable);
				}
				if (AddWordToHashTable(hashTable, userAnswKey, userAnswVal))
				{
					cout << "Value added!" << endl;
				}
				else
				{
					cout << "Same key-value already exists!" << endl;
				}
			}
			else
			{
				hashTable = InitHashTable(DictConst);
				hashCreated = true;
				AddWordToHashTable(hashTable, userAnswKey, userAnswVal);
			}
			std::system("pause");
			break;
		}
		case 2:
			if (hashCreated)
			{
				string userAnswKey;
				cout << "What the key you want to delete? " << endl;
				cin >> userAnswKey;
				tempList = &hashTable->List[HashFunc(userAnswKey, hashTable)];

				if (tempList->Length != 0)
				{
					DeleteNode(tempList, userAnswKey);
					hashTable->CountElem--;
				}
				else
				{
					cout << "You probably have a mistake?" << endl;
				}
			}
			else
			{
				cout << "You need create a hash table firstly!" << endl;
			}
			std::system("pause");
			break;
		case 3:
		{
			string userAnswKey;
			cout << "Enter key for search in the hash table: " << endl;
			cin >> userAnswKey;
			Node* searchNode = Search(userAnswKey, hashTable);
			if (searchNode == nullptr)
			{
				cout << "This key doesn't exist!" << endl;
			}
			else
			{
				cout << "Founded: " << endl
					<< searchNode->Key << '\t' << searchNode->Value << "\t\n";
				while (searchNode->NextNode != nullptr)
				{
					searchNode = searchNode->NextNode;
					if (searchNode->Key == userAnswKey)
					{
						cout << searchNode->Key << '\t' << searchNode->Value << endl;
					}
				}
			}
			cout << endl;
			std::system("pause");
			break;
		}
		case 0:
			return;
		default:
			cout << "You should choice number from menu!" << endl;
			std::system("pause");
			break;
		}

	}
}