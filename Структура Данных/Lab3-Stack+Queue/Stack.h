#pragma once
using namespace std;
const int Size(3);

struct Stack
{
	int* Buffer;
	int BufferSize;
	int Top;
};


Stack* CreateStack(int data);
void Push(Stack* stack, int data);
int Pop(Stack* stack);
bool IsEmpty(Stack* stack);
void Delete(Stack* stack);
int* OverTopPointer(Stack* stack);
void ChangeSize(Stack* stack, int size);