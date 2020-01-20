#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

struct List
{
	Node* Head;
	Node* Tail;
	int Capacity;
};

void InitHead(List* list, int item);
void AddHead(List* list, int item);
void DelHead(List* list);
void Swap(Node* first, Node* second);

Node* FindNodePointerByCount(List* head, int count);
Node* FindMinNode(List* head);
Node* FindMinFromNode(Node* node);
Node* LinearSearch(List* list, int item);
Node* ListSort(List* head);