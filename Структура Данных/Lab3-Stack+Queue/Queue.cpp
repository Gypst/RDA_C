#include "Queue.h"

void Enqueue(Queue* queue, int data)
{
	*queue->Tail = data;
	queue->Items++;
	queue->Tail++;
}

int Dequeue(Queue* queue)
{
	int returnValue;
	returnValue = *queue->Buffer;

	GoQueue(queue);
	queue->Tail--;
	queue->Items--;
	return returnValue;
}

void GoQueue(Queue* queue)
{
	for (int i = 0; i < queue->BufferSize - 1; i++)
	{
		*(queue->Buffer + i) = *(queue->Buffer + 1 + i);
	}
}

bool IsEmpty(Queue* queue)
{
	return queue->Buffer == queue->Tail;
}

void Delete(Queue* queue)
{
	delete[] queue->Buffer;
	queue->Tail = queue->Buffer;
}

void NullFilling(Queue* queue)
{
	for (int i = 0; i < queue->BufferSize; i++)
	{
		*(queue->Buffer + i) = 0;
	}
}
void ChangeSize(Queue* queue, int size)
{
	int* oldBuffer = queue->Buffer;
	int* oldTail = queue->Tail;

	queue->Buffer = new int[size];
	for (int i = 0; i <= queue->BufferSize; i++)
	{
		*(queue->Buffer + i) = *(oldBuffer + i);

		if (oldBuffer + i == oldTail)
		{
			queue->Tail = queue->Buffer + i;
		}
	}

	queue->BufferSize = size;
}
