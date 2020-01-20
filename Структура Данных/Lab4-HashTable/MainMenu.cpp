#include "DictionaryMenu.h"
#include "HashTableMenu.h"
#include <iostream>

void main()
{
	while (true)
	{
		system("CLS");
		cout << "1. Dictionary" << endl
			 << "2. Hashtable"	<< endl
		 	 << "0. Exit"		<< endl;

		int userAnswer = GetInt();
		switch (userAnswer)
		{
		case 1:
			DictionaryMenu();
			break;
		case 2:
			HashMenu();
			break;
		case 0:
			return;
		default:
			break;
		}
	}
}