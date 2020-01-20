#pragma once
#include "Stack.h"
using namespace std;
const int SizeQueue(3);

struct StackQueue
{
	Stack* InputStack;
	Stack* OutputStack;

	StackQueue();
	~StackQueue();
};

void ChangeSizeStackQueue(StackQueue* stackQueue, int size);
void FillOutputStack(StackQueue* stackQueue);
void PushStackQueue(StackQueue* stackQueue, int data);
int PopStackQueue(StackQueue* stackQueue);