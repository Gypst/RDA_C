#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	_headTree = nullptr;
}

BinaryTree::~BinaryTree()
{
	while (_headTree != nullptr)
	{
		Remove(FindMin());
	}
}

int BinaryTree::FindMin()
{
	Node* supNode = _headTree;
	while (supNode->LeftNode != nullptr)
	{
		supNode = supNode->LeftNode;
	}
	return supNode->Key;
}

int BinaryTree::FindMax()
{
	Node* supNode = _headTree;
	while (supNode->RightNode != nullptr)
	{
		supNode = supNode->RightNode;
	}
	return supNode->Key;
}

int BinaryTree::FindAndDeleteMin(Node* binaryTreeNode,int dir)
{
	Node* supNode = binaryTreeNode;
	while (supNode->LeftNode != nullptr)
	{
		supNode = supNode->LeftNode;
		dir = 0;
	}
	int value = supNode->Key;
	if (dir == 0)
	{
		supNode->ParentNode->LeftNode = nullptr;
	}
	else
	{
		if (supNode->RightNode != nullptr)
		{
			supNode->ParentNode->RightNode = supNode->RightNode;
			supNode->RightNode->ParentNode = supNode->ParentNode;
		}
		else
		{
			supNode->ParentNode->RightNode = nullptr;
		}
	}
	delete supNode;
	return value;
}

bool BinaryTree::Find(int key)
{
	Node* supNode;
	if (_headTree == nullptr)
	{
		return false;
	}
	else
	{
		supNode = _headTree;
		while (supNode!=nullptr)
		{
			if (supNode->Key == key)
			{
				return true;
			}
			if (supNode->Key > key)
			{
				supNode = supNode->LeftNode;
			}
			else
			{
				supNode = supNode->RightNode;
			}
		}
		return false;
	}
}

void BinaryTree::Insert(int key)
{
	if (_headTree == nullptr)
	{
		_headTree = new Node;
		_headTree->Key = key;
		return;
	}
	if (_headTree->Key == key)
	{
		return;
	}
	AddNode(key, _headTree);
}

void BinaryTree::Remove(int key)
{
	if (_headTree == nullptr)
	{
		return;
	}
	if (_headTree->Key == key)
	{
		if (_headTree->RightNode != nullptr)
		{
			_headTree->Key = FindAndDeleteMin(_headTree->RightNode, 1);
			return;
		}
		if (_headTree->LeftNode != nullptr)
		{
			_headTree = _headTree->LeftNode;
			delete _headTree->ParentNode;
			_headTree->ParentNode = nullptr;
			return;
		}
		else
		{
			delete _headTree;
			_headTree = nullptr;
			return;
		}
	}
	CheckNode(key, _headTree, -1);
}

void BinaryTree::AddNode(int key, Node* binaryTreeNode)
{
	if (binaryTreeNode->Key == key)
	{
		return;
	}
	if (binaryTreeNode->Key > key)
	{
		if (binaryTreeNode->LeftNode == nullptr)
		{
			binaryTreeNode->LeftNode = new Node;
			binaryTreeNode->LeftNode->Key = key;
			binaryTreeNode->LeftNode->ParentNode = binaryTreeNode;
			return;
		}
		else
		{
			AddNode(key, binaryTreeNode->LeftNode);
			return;
		}
	}
	else
	{
		if (binaryTreeNode->RightNode == nullptr)
		{
			binaryTreeNode->RightNode = new Node;
			binaryTreeNode->RightNode->Key = key;
			binaryTreeNode->RightNode->ParentNode = binaryTreeNode;
			return;
		}
		else
		{
			AddNode(key, binaryTreeNode->RightNode);
			return;
		}
	}
}

void BinaryTree::DeleteNode(Node* binaryTreeNod, int dir)
{
	if (binaryTreeNod->RightNode != nullptr && binaryTreeNod->LeftNode != nullptr)
	{
		binaryTreeNod->Key = FindAndDeleteMin(binaryTreeNod->RightNode, 1);
		return;
	}
	if (binaryTreeNod->LeftNode != nullptr&&binaryTreeNod->RightNode==nullptr)
	{
		if (dir == 0)
		{
			binaryTreeNod->ParentNode->LeftNode = binaryTreeNod->LeftNode;
		}
		else
		{
			binaryTreeNod->ParentNode->RightNode = binaryTreeNod->LeftNode;	
		}
		binaryTreeNod->LeftNode->ParentNode = binaryTreeNod->ParentNode;
		delete binaryTreeNod;
		return;
	}
	else if(binaryTreeNod->LeftNode == nullptr && binaryTreeNod->RightNode != nullptr)
	{
		binaryTreeNod->Key = FindAndDeleteMin(binaryTreeNod->RightNode, 1);
		return;
	}
	else
	{
		if (dir == 0)
		{
			binaryTreeNod->ParentNode->LeftNode = nullptr;
		}
		else
		{
			binaryTreeNod->ParentNode->RightNode = nullptr;
		}
		delete binaryTreeNod;
		return;
	}
}

void BinaryTree::CheckNode(int key, Node* binaryTreeNode, int dir)
{
	if (key == binaryTreeNode->Key)
	{
		DeleteNode(binaryTreeNode, dir);
	}
	else if (key < binaryTreeNode->Key && binaryTreeNode->LeftNode != nullptr)
	{
		CheckNode(key, binaryTreeNode->LeftNode, 0);
	}
	else if (key > binaryTreeNode->Key&& binaryTreeNode->RightNode != nullptr)
	{
		CheckNode(key, binaryTreeNode->RightNode, 1);
	}
}

//void BinaryTree::PushToQueue(Node* queue, int* len, Node* node)
//{
//	if (node->LeftNode != nullptr)
//	{
//		queue->LeftNode = node->LeftNode;
//		len++;
//	}
//	if (node->RightNode != nullptr)
//	{
//		queue->LeftNode = node->RightNode;
//		len++;
//	}
//}
//
