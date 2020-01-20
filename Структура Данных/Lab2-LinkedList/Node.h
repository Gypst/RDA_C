#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int Data;
	Node* Next;
	Node* Prev;
};

Node* AddElem(Node* oldNode, int item);
Node* DelElem(Node* myNode);