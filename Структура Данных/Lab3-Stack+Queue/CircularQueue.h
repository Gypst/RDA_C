#pragma once
const int CircularQueueSize = 3;

struct CircularQueue
{
	int* Buffer;
	int BufferSize;
	int* Head;
	int* Tail;
	int Items;
};

void Enqueue(CircularQueue* queue, int data);
int Dequeue(CircularQueue* queue);
bool IsEmpty(CircularQueue* queue);
void Delete(CircularQueue* queue);
int* FreeBuffer(CircularQueue* queue);
void GoHead(CircularQueue* queue);
void NullFilling(CircularQueue* queue);
CircularQueue* ChangeSize(CircularQueue* queue, int size);