#include "StackQueue.h"

StackQueue::StackQueue()
{
	InputStack = new Stack;
	InputStack->Buffer = new int[SizeQueue];
	InputStack->BufferSize = SizeQueue;
	InputStack->Top = 0;

	OutputStack = new Stack;
	OutputStack->Buffer = new int[SizeQueue];
	OutputStack->BufferSize = SizeQueue;
	OutputStack->Top = 0;
}

StackQueue::~StackQueue()
{
	delete[] InputStack->Buffer;
	delete[] OutputStack->Buffer;
}

void ChangeSizeStackQueue(StackQueue* stackQueue, int size)
{
	ChangeSize(stackQueue->InputStack, size);
	ChangeSize(stackQueue->OutputStack, size);
}

//if ONLY Output stack is empty!
void FillOutputStack(StackQueue* stackQueue) 
{
	while (stackQueue->InputStack->Top > 0)
	{
		Push(stackQueue->OutputStack, Pop(stackQueue->InputStack));
	}
}

void PushStackQueue(StackQueue* stackQueue, int data)
{
	Push(stackQueue->InputStack, data);
}

int PopStackQueue(StackQueue* stackQueue)
{
	int result;
	if (stackQueue->OutputStack->Top < 1)
	{
		FillOutputStack(stackQueue);
		result = Pop(stackQueue->OutputStack);
	}
	else
	{
		result = Pop(stackQueue->OutputStack);
	}

	return result;
}