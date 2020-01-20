#include "CircularQueue.h"

void Enqueue(CircularQueue* queue, int data)
{
	if (queue->Items / queue->BufferSize > 0)
	{
		GoHead(queue);
	}

	*queue->Tail = data;

	if (queue->Tail == queue->Buffer + queue->BufferSize - 1)
	{
		queue->Tail = queue->Buffer;
	}
	else
	{
		queue->Tail++;
	}

	queue->Items++;
}

int Dequeue(CircularQueue* queue)
{
	int returnValue;
	returnValue = *queue->Head;
	*queue->Head = 0;
	GoHead(queue);
	queue->Items--;
	return returnValue;
}

void GoHead(CircularQueue* queue)
{
	if (queue->Head == queue->Buffer + queue->BufferSize - 1)
	{
		queue->Head = queue->Buffer;
	}
	else
	{
		queue->Head++;
	}
}

bool IsEmpty(CircularQueue* queue)
{
	return queue->Items == 0;
}

void Delete(CircularQueue* queue)
{
	delete[] queue->Buffer;
	queue->Head = queue->Buffer;
	queue->Tail = queue->Buffer;
}

int* occupiedbuffer(CircularQueue* queue)
{
	return queue->Head;
}

int* FreeBuffer(CircularQueue* queue)
{
	return queue->Tail;
}

void NullFilling(CircularQueue* queue)
{
	for (int i = 0; i < queue->BufferSize; i++)
	{
		*(queue->Buffer + i) = 0;
	}
}

CircularQueue* ChangeSize(CircularQueue* queue, int size)
{
	CircularQueue* tempQueue = new CircularQueue;
	tempQueue->Items = 0;
	tempQueue->BufferSize = size;
	tempQueue->Buffer = new int[size];
	tempQueue->Head = tempQueue->Buffer;
	tempQueue->Tail = tempQueue->Buffer;

	NullFilling(tempQueue);

	while (queue->Items > 0)
	{
		Enqueue(tempQueue, Dequeue(queue));
	}

	return tempQueue;
}