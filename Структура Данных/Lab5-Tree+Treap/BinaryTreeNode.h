#pragma once
struct Node
{
	int Key;
	Node* LeftNode = nullptr;
	Node* RightNode = nullptr;
	Node* ParentNode = nullptr;
};