#include "List.h"

void InitHead(List* list, int item)
{
	Node* headNode;
	headNode = new Node;

	headNode->Data = item;
	headNode->Next = nullptr;
	headNode->Prev = nullptr;

	list->Head = headNode;
}

void AddHead(List* list, int item)
{
	Node* headList = list->Head;
	Node* newHead;
	newHead = new Node;

	headList->Prev = newHead;
	newHead->Next = headList;
	newHead->Prev = nullptr;
	newHead->Data = item;

	list->Head = newHead;
	return;
}

void DelHead(List* list)
{
	Node* newHead = list->Head->Next;
	newHead->Prev = nullptr;
	delete[] list->Head;
	list->Head = newHead;
}

Node* FindNodePointerByCount(List* list, int count)
{
	//Check count
	if (count < 0)
	{
		return nullptr;
	}
	//TempRider :D
	Node* temp;
	temp = new Node;
	temp = list->Head;

	while (count > 1)
	{
		temp = temp->Next;
		if (temp == nullptr)
		{
			//count over list
			return nullptr; 
		}
		count--;
	}
	return temp;
};


Node* FindMinNode(List* list)
{
	Node* minNode = list->Head;

	Node* rider = list->Head;
	while (rider->Next != nullptr)
	{
		rider = rider->Next;
		if (minNode->Data > rider->Data)
		{
			minNode = rider;
		}
	}

	return minNode;
}

Node* FindMinFromNode(Node* node)
{
	Node* minNode = node;
	Node* rider = node;

	while (rider->Next != nullptr)
	{
		rider = rider->Next;
		if (minNode->Data > rider->Data)
		{
			minNode = rider;
		}
	}

	return minNode;
}

Node* LinearSearch(List* list, int item)
{
	Node* head = list->Head;
	int nodeElement = head->Data;

	while (nodeElement != item)
	{
		if (head->Next == nullptr)
		{
			return nullptr;
		}
		head = head->Next;
		nodeElement = head->Data;
	}
	return head;
}

Node* ListSort(List* list)
{
	// The pointer where fin ListSort
	Node* sortedList;
	sortedList = list->Head;

	// The end of list

	Node* end = list->Head;
	while (end->Next != nullptr)
	{
		end = end->Next;
	}

	while (sortedList->Next != nullptr)
	{
		Node* min = FindMinFromNode(sortedList);

		if (sortedList != min)
		{
			//Repaire pointer of list before cut min list (like delete a Node)
			if (min->Next != nullptr)
			{
				min->Next->Prev = min->Prev;
			}
			if (min->Prev != nullptr)
			{
				min->Prev->Next = min->Next;
			}
		}

		//Add min before sortedList (head firstly)
		if (sortedList != min)
		{
			min->Next = sortedList;
			if (sortedList->Prev == nullptr)
			{
				min->Prev = nullptr;
				list->Head = min;
			}
			else
			{
				min->Prev = sortedList->Prev;
				sortedList->Prev->Next = min;
			}
			sortedList->Prev = min;
			continue;
		}
		sortedList = sortedList->Next;
		continue;
	}

	return list->Head;
}

void Swap(Node* first, Node* second)
{
	second->Prev = first->Prev;

	first->Next = second->Next;
	first->Prev = second;

	second->Next = first;
}