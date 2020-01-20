#include "BinaryTreeMenu.h"
#include "TreapMenu.h"
#include "Treap.h"
#include "GetInt.h"
#include <iostream>
using namespace std;

void main()
{
	while (true)
	{
		system("CLS");
		cout << "1. Binary Tree"	<< endl;
		cout << "2. Treap"			<< endl;
		cout << "0. Exit"			<< endl;

		int userAnswer = GetInt();
		switch (userAnswer)
		{
		case 1:
			BinaryTreeMenu();
			break;
		case 2:
			TreapMenu();
			break;
		case 0:
			return;
		default:
			break;
		}
	}
}