#include "StackQueueMenu.h"

void ShowStack(StackQueue* stack, bool StackCreated)
{
	if (StackCreated)
	{
		cout << "Input stack: " << endl;
		for (int i = 0; i < stack->InputStack->Top; i++)
		{
			cout << stack->InputStack->Buffer[i] << '\t';
		}
		cout << endl;

		cout << "Output stack: " << endl;
		for (int i = 0; i < stack->OutputStack->Top; i++)
		{
			cout << stack->OutputStack->Buffer[i] << '\t';
		}
		cout << endl;
	}
	else
	{
		cout << "Stack is empty!" << endl;
	}
}

void StackQueueMenu()
{
	StackQueue stack;
	bool StackCreated = false;

	while (true)
	{
		system("CLS");
		if (StackCreated)
		{
			ShowStack(&stack, StackCreated);
		}
		cout << endl;
		cout << "Menu of queue with stack:"		<< endl
			<< "1. Push number"					<< endl
			<< "2. Pop number"					<< endl
			<< "3. Expand stack size"			<< endl
			<< "0. Exit"						<< endl;

		int userAnswer = GetInt();
		switch (userAnswer)
		{
		case 1:
				if (stack.InputStack->Top < stack.InputStack->BufferSize)
				{
					cout << "Enter a number" << endl;
					userAnswer = GetInt();
					PushStackQueue(&stack, userAnswer);
				}
				else
				{
					cout << "Stack is full" << endl;
					system("pause");
					break;
				}
				StackCreated = true;
				break;

		case 2:

			if (stack.InputStack->Top < 1 && stack.OutputStack->Top < 1)
			{
				cout << "Empty stack!" << endl;
			}
			else
			{
				cout << "Output value: ";
				cout << PopStackQueue(&stack) << endl;
			}

			system("pause");
			break;

		case 3:
			userAnswer = stack.InputStack->BufferSize * 2;
			ChangeSizeStackQueue(&stack, userAnswer);
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