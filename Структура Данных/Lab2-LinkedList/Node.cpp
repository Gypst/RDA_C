#include "Node.h"

Node* AddElem(Node* oldNode, int item)
{
	Node* temp;
	Node* NextNode;

	temp = new Node;
	NextNode = oldNode->Next;

	temp->Data = item;

	oldNode->Next = temp;
	temp->Prev = oldNode;
	temp->Next = NextNode;

	if (NextNode != nullptr)
	{
		NextNode->Prev = temp;
	}
	return temp;
}

Node* DelElem(Node* myNode)
{
	Node* prev = myNode->Prev;
	Node* next = myNode->Next;

	if (prev != nullptr)
	{
		prev->Next = next;
	}
	if (next != nullptr)
	{
		next->Prev = prev;
	}

	delete[] myNode;

	// IF deleted head
	if (prev == nullptr)
	{
		return next;
	}
	// IF not headNode, find and return head
	while (prev->Prev != nullptr)
	{
		prev = prev->Prev;
	}
	return prev;
}