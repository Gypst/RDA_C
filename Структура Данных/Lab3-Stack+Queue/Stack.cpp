#include "Stack.h"

Stack* CreateStack(int data)
{
	Stack* stack;
	stack = new Stack;
	stack->Buffer = new int[Size];
	stack->BufferSize = Size;
	*stack->Buffer = data;
	stack->Top = 1;
	return stack;
}

void Push(Stack* stack, int data)
{
	*OverTopPointer(stack) = data;
	stack->Top++;
}

int Pop(Stack* stack)
{
	stack->Top--;
	return *OverTopPointer(stack);
}

bool IsEmpty(Stack* stack)
{
	return stack->Top < 1;
}

void Delete(Stack* stack)
{
	if (stack != nullptr)
	{
		delete[] stack->Buffer;
	}
}

int* OverTopPointer(Stack* stack)
{
	int* Iterator = stack->Buffer;
	for (int i = 0; i < stack->Top; i++)
	{
		Iterator++;
	}
	return Iterator;
}

void ChangeSize(Stack* stack,int size) 
{
	int* oldBuffer;
	oldBuffer = stack->Buffer;

	stack->Buffer = new int[size];

	for (int i = 0; i < stack->BufferSize; i++)
	{
		stack->Buffer[i] = oldBuffer[i];
	}

	delete[] oldBuffer;

	stack->BufferSize = size;
}
