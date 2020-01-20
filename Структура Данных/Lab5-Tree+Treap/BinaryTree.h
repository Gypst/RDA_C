#pragma once
#include "BinaryTreeNode.h"

struct BinaryTree
{
private:
	int FindAndDeleteMin(Node* binaryTreeNode, int dir);
	void AddNode(int key, Node* binaryTreeNod);
	void DeleteNode(Node* binaryTreeNod, int dir);
	void CheckNode(int key, Node* binaryTreeNode, int dir);
	//void PushToQueue(Node* queue, int* len, Node* node);
public:
	BinaryTree();
	~BinaryTree();
	Node* _headTree;
	int FindMin();
	int FindMax();
	bool Find(int key);
	void Insert(int key);
	void Remove(int key);
};