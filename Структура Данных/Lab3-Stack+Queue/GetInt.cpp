#include "GetInt.h"

int GetInt()
{
	int userAnswer;
	while (!(cin >> userAnswer))
	{
		cout << "This is not a natural number" << endl;

		cin.clear();
		//Discard previous input 
		cin.ignore(132, '\n');
	}
	return userAnswer;
}