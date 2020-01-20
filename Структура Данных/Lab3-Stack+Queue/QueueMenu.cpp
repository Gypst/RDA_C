#include "QueueMenu.h"

void ShowQueue(Queue* queue)
{
	for (int i = 0; i < queue->BufferSize; i++)
	{
		if (queue->Items - i > 0)
		{
			cout << *(queue->Buffer + i) << '\t';
		}
		else
		{
			cout << "X \t";
		}

	}
	cout << endl;
}

void QueueMenu()
{
	Queue queue;
	queue.BufferSize = QueueSize;
	queue.Buffer = new int[queue.BufferSize];
	queue.Tail = queue.Buffer;
	queue.Items = 0;
	while (true)
	{
		system("CLS");
		ShowQueue(&queue);
		cout << endl;
		cout << "Menu of queue based on circular queue:" << endl
			<< "1. Enqueue number" << endl
			<< "2. Dequeue number" << endl
			<< "3. Change queue size" << endl
			<< "0. Exit" << endl;
		
		int userAnswer = GetInt();
		switch (userAnswer)
		{
		case 1:
			if (queue.BufferSize == queue.Items)
			{
				cout << "Queue is full!" << endl;
				system("pause");
				break;
			}
			cout << "Enter the number" << endl;
			userAnswer = GetInt();
			Enqueue(&queue, userAnswer);
			break;

		case 2:

			if (queue.Items <= 0)
			{
				cout << "Need your numbers firstly!" << endl;
				system("pause");
				break;
			}
			cout << "The number from queue: " << Dequeue(&queue) << endl;
			system("pause");
			break;

		case 3:
			userAnswer = queue.BufferSize * 2;
			ChangeSize(&queue, userAnswer);
			break;

		case 0:
			Delete(&queue);
			return;
			break;

		default:
			cout << "You should choice number from menu!" << endl;
			system("pause");
			break;
		}
	}
}