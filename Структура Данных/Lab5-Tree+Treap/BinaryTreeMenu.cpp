#include "BinaryTreeMenu.h"

void PrintBinTree(Node* headTree)
{
	if (headTree != nullptr)
	{
		cout << "Node Key: " << headTree->Key;
		if (headTree->LeftNode != nullptr)
		{
			cout << " |Left Key:" << headTree->LeftNode->Key;
		}
		if (headTree->RightNode != nullptr)
		{
			cout << " |Right Key:" << headTree->RightNode->Key;
		}
		cout << endl;
		if (headTree->LeftNode != nullptr)
		{
			PrintBinTree(headTree->LeftNode);
		}
		if (headTree->RightNode != nullptr)
		{
			PrintBinTree(headTree->RightNode);
		}
	}
}

void BinaryTreeMenu()
{
	BinaryTree tree;
	bool treeExist = false;

	while (true)
	{
		system("CLS");
		PrintBinTree(tree._headTree);
		cout << "1. Insert" << endl;
		cout << "2. Find min" << endl;
		cout << "3. Find max" << endl;
		cout << "4. Find by key" << endl;
		cout << "5. Remove" << endl;
		cout << "0. Exit" << endl;
	
		int userAnswer = GetInt();
		switch (userAnswer)
		{
		case 1:
		{
			cout << "Enter value: ";
			int value = GetInt();
			if (tree.Find(value))
			{
				cout << "Node alreasy exists" << endl;
				system("pause");
			}
			else
			{
				tree.Insert(value);
				treeExist = true;
			}
			break;
		}
		case 2:
			if (treeExist)
			{
				cout << "Minimum = " << tree.FindMin() << endl;
			}
			else
			{
				cout << "Create tree firstly!";
			}
			system("pause");
			break;
		case 3:
			if (treeExist)
			{
				cout << "Maximum = " << tree.FindMax() << endl;
			}
			else
			{
				cout << "Tree does not exist yet!";
			}
			system("pause");
			break;
		case 4:
		{
			cout << "Enter value: ";
			int value = GetInt();
			if (tree.Find(value))
			{
				cout << "Node exists" << endl;
			}
			else
			{
				cout << "Node does not exists!" << endl;
			}
			system("pause");
			break;
		}
		case 5:
		{
			cout << "Enter value: ";
			int value = GetInt();
			tree.Remove(value);
			break;
		}
		case 0:
			return;
		}
	}
}

