#pragma once
const int QueueSize = 3;

struct Queue
{
	int* Buffer;
	int BufferSize;
	int* Tail;
	int Items;
};

void Enqueue(Queue* queue, int data);
int Dequeue(Queue* queue);
bool IsEmpty(Queue* queue);
void Delete(Queue* queue);
void GoQueue(Queue* queue);
void NullFilling(Queue* queue);
void ChangeSize(Queue* queue, int size);
