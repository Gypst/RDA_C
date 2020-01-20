#include "DictionaryMenu.h"

void ShowDictionary(Dictionary* dictionary)
{
	Node* tempNode;
	int count = 0;
	cout << "Dictionary: " << endl;

	for (int i = 0; i < dictionary->Table->Capacity; i++)
	{
		tempNode = dictionary->Table->List[i].Head;

		if (dictionary->Table->List[i].Length != 0)
		{
			while (tempNode != nullptr)
			{
				cout << count << ". " << tempNode->Key << '\t' << tempNode->Value;
				tempNode = tempNode->NextNode;
				cout << endl;
				count++;
			}
		}
	}
	if (count == 0)
	{
		cout << "Empty Dictionary ;<" << endl;
	}
}

void DictionaryMenu()
{
	Dictionary* dictionary = new Dictionary;
	dictionary->Table = nullptr;
	bool hashCreated = false;
	List* tempList = nullptr;

	while (true)
	{
		std::system("CLS");

		if (hashCreated)
		{
			ShowDictionary(dictionary);
			//if need check with hash table 
			//ShowTable(dictionary->Table);
		}

		cout << "Menu of Dictionary:" << endl
			<< "1. Add word" << endl
			<< "2. Delete word" << endl
			<< "3. Search word" << endl
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

			cout << "Enter line for the keyword: " << endl;
			string userAnswVal;
			getline(cin, userAnswVal);

			if (hashCreated)
			{
				int occupancy = dictionary->Table->CountElem;
				if (occupancy >= OccupancyRate * dictionary->Table->Capacity)
				{
					dictionary->Table = ReHash(dictionary->Table);
				}
				if (AddWordToDic(dictionary, userAnswKey, userAnswVal))
				{
					cout << "Value added!" << endl;
				}
				else
				{
					cout << "Same key already exists!" << endl;
				}
			}
			else
			{
				dictionary->Table = InitHashTable(DictConst);
				hashCreated = true;
				AddWordToDic(dictionary, userAnswKey, userAnswVal);
				cout << "Value added!" << endl;
			}
			std::system("pause");
			break;
		}
		case 2:
		{
			if (hashCreated)
			{
				cout << "What the keyWord you want to delete? " << endl;
				string userAnswKey;
				cin >> userAnswKey;
				tempList = &dictionary->Table->List[HashFunc(userAnswKey, dictionary->Table)];

				if (tempList->Length != 0)
				{
					DeleteNode(tempList, userAnswKey);
				}
				else
				{
					cout << "You probably have a mistake?" << endl;
				}
			}
			else
			{
				cout << "You need create dictionary firstly!" << endl;
			}
			break;
		}
		case 3:
		{
			cout << "Enter keyWord for search in dictionary: " << endl;
			string userAnswKey;
			cin >> userAnswKey;
			Node* searchAnsw = Search(dictionary, userAnswKey);
			if (searchAnsw == nullptr)
			{
				cout << "This keyWord doesn't exist!" << endl;
				std::system("pause");
			}
			else
			{
				cout << "Founded: " << searchAnsw->Key << '\t' << searchAnsw->Value << endl;
				std::system("pause");
			}
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