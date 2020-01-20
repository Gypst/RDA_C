#include <iostream>
#include "GetInt.h"
#include "StackMenu.h"
#include "CircularQueueMenu.h"
#include "QueueMenu.h"
#include "StackQueueMenu.h"
using namespace std;

void main()
{
	while (true)
	{
		system("CLS");

		cout << "Main menu:"			<< endl
			<< "1. Stack"				<< endl
			<< "2. Circular queue"		<< endl
			<< "3. Queue"				<< endl
			<< "4. StackQueue"			<< endl
			<< "0. Exit"				<< endl;

		int userAnswer = GetInt();

		switch (userAnswer)
		{
		case 1:
			StackMenu();
			break;

		case 2:
			CircularQueueMenu();
			break;

		case 3:
			QueueMenu();
			break;
		case 4:
			StackQueueMenu();
			break;

		case 0:
			return;

		default:
			cout << "You should choice number from menu!" << endl;
			system("pause");
			break;
		}
	}
}