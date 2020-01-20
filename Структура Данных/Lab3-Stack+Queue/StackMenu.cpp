#include "StackMenu.h"
#include "GetInt.h"

void ShowStack(Stack* stack, bool StackCreated)
{
	if (StackCreated)
	{
		int* Iterator = stack->Buffer;
		for (int i = 0; i < stack->Top; i++)
		{
			cout << *Iterator << '\t';
			Iterator++;
		}
		cout << endl;
	}
	else
	{
		cout << "Stack is empty!" << endl;
	}
}

void StackMenu()
{
	Stack* stack = nullptr;
	bool StackCreated = false;

	while (true)
	{
		system("CLS");
		if (StackCreated)
		{
			ShowStack(stack, StackCreated);
		}
		cout << endl;
		cout << "Menu of stack:" << endl
			<< "1. Push number" << endl
			<< "2. Pop number" << endl
			<< "3. Expand stack size" << endl
			<< "0. Exit" << endl;

		int userAnswer = GetInt();
		switch (userAnswer)
		{
		case 1:
			if (StackCreated)
			{
				if (stack->Top < stack->BufferSize)
				{
					cout << "Enter a number" << endl;
					userAnswer = GetInt();
					Push(stack, userAnswer);
				}
				else
				{
					cout << "Stack is full" << endl;
					system("pause");
					break;
				}

			}
			else
			{
				cout << "Enter a number" << endl;
				userAnswer = GetInt();
				stack = CreateStack(userAnswer);
			}
			StackCreated = true;
			break;

		case 2:
			if (stack->Top >= 1)
			{
				cout << Pop(stack) << endl;
			}
			else
			{
				cout << "Stack is empty" << endl;
			}
			system("pause");
			break;

		case 3:
			userAnswer = stack->BufferSize * 2;
			ChangeSize(stack, userAnswer);
			break;

		case 0:
			Delete(stack);
			StackCreated = false;
			return;
			break;

		default:
			cout << "You should choice number from menu!" << endl;
			system("pause");
			break;
		}
	}
}