#include "CircularQueueMenu.h"
#include "GetInt.h"

void ShowQueue(CircularQueue *queue)
{
	for (int i = 0; i < queue->BufferSize; i++)
	{
		cout << *(queue->Buffer + i) << "\t";
	}
	cout << endl;
}

void CircularQueueMenu()
{
	CircularQueue* queue = new CircularQueue;
	queue->BufferSize = CircularQueueSize;
	queue->Buffer = new int[queue->BufferSize];
	queue->Head = queue->Buffer;
	queue->Tail = queue->Buffer;
	queue->Items = 0;

	NullFilling(queue);
	while (true)
	{
		system("CLS");
		ShowQueue(queue);
		cout << endl;
		cout << "Menu of circular queue:" << endl
			<< "1. Enqueue number" << endl
			<< "2. Dequeue number" << endl
			<< "3. Expand size of circular queue" << endl
			<< "0. Exit" << endl;

		int userAnswer = GetInt();
		if (queue->Items > queue->BufferSize)
		{
			queue->Items = queue->BufferSize;
		}
		switch (userAnswer)
		{
		case 1:

			cout << "Enter the number" << endl;
			userAnswer = GetInt();
			Enqueue(queue, userAnswer);
			break;

		case 2:

			if (queue->Items <= 0)
			{
				cout << "Need your numbers firstly!" << endl;
				system("pause");
				break;
			}
			cout << "The number from queue: " << Dequeue(queue) << endl;
			system("pause");
			break;

		case 3:
			queue = ChangeSize(queue, queue->BufferSize * 2);
			break;

		case 0:

			Delete(queue);
			return;
			break;

		default:
			cout << "You should choice number from menu!" << endl;
			system("pause");
			break;
		}
	}

}