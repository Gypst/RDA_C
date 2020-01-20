#include "TreapMenu.h"
#include<iostream>
#include <random>
using namespace std;

void PrintTreap(NodeTreap* headTree)
{
	if (headTree != nullptr)
	{
		cout << "Node Key: " << headTree->Key <<" Priority: " << headTree->Priority;
		if (headTree->LeftNode != nullptr)
		{
			cout << " |Left: " << headTree->LeftNode->Key << " ; " << headTree->LeftNode->Priority;;
		}
		if (headTree->RightNode != nullptr)
		{
			cout << " |Right: " << headTree->RightNode->Key << " ; " << headTree->RightNode->Priority;
		}
		cout << endl;
		if (headTree->LeftNode != nullptr)
		{
			PrintTreap(headTree->LeftNode);
		}
		if (headTree->RightNode != nullptr)
		{
			PrintTreap(headTree->RightNode);
		}
	}
}

void TreapMenu()
{
	//It produce random numbers by accessing the
	//operational system's entropy pool via system calls
	random_device random_device; 
	mt19937 generator(random_device()); 
	uniform_int_distribution<> distribution(0, 300); 

	int option;
	int key;
	int priority;
	Treap treap;
	bool treapExist = false;

	while (true)
	{
		system("CLS");
		PrintTreap(treap._headTreap);

		cout << "1. Insert(1S2M)"	<< endl;
		cout << "2. Insert(1S)"		<< endl;
		cout << "3. Remove(2S1M)"	<< endl;
		cout << "4. Remove(1M)"		<< endl;
		cout << "5. Find by key"	<< endl;
		cout << "0. Exit"			<< endl;

		int userAnswer = GetInt();
		switch (userAnswer)
		{
		case 1:
			cout << "Enter key: ";
			key = GetInt();
			if (treap.Find(key))
			{
				cout << "Node already exists" << endl;
			}
			else
			{
				priority = distribution(generator);
				treap.Insert1S2M(key, priority);
				treapExist = true;
			}
			system("pause");
			break;
		case 2:
			cout << "Enter key: ";
			key = GetInt();
			if (treap.Find(key))
			{
				cout << "Node already exists" << endl;
			}
			else
			{
				priority = distribution(generator);
				treap.Insert1S(key, priority);
				treapExist = true;
			}
			system("pause");
			break;
		case 3:
			if (treapExist)
			{
				cout << "Enter key: ";
				key = GetInt();
				treap.Remove2S1M(key);
			}
			else
			{
				cout << "Create treap firstly!" << endl;
				system("pause");
			}
			break;
		case 4:
			if (treapExist)
			{
				cout << "Enter key: ";
				key = GetInt();
				treap.Remove1M(key);
			}
			else
			{
				cout << "Create treap firstly!" << endl;
				system("pause");
			}
			break;
		case 5:
			if (treapExist)
			{
				cout << "Enter key: ";
				key = GetInt();
				if (treap.Find(key))
				{
					cout << "Node exists" << endl;
				}
				else
				{
					cout << "Node does not exists" << endl;
				}
			}
			else
			{
				cout << "Create treap firstly!" << endl;
			}
			system("pause");
			break;
		case 0:
			return;
		}
	}
}
