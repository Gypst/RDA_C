#include "Treap.h"

Treap::Treap()
{
	_headTreap = nullptr;
}

Treap::~Treap()
{
	NodeTreap* startQueue = nullptr;
	int len = 0;
	if (_headTreap != nullptr)
	{
		startQueue = _headTreap;
		len++;
		PushToQueue(startQueue, &len, _headTreap);
	}
	for (int i = 0; i < len; i++)
	{
		NodeTreap* nextNode = startQueue->LeftNode;
		delete startQueue;
		startQueue = nextNode;
	}
}

void Treap::Split(NodeTreap*& treap, int key, NodeTreap*& treapL, NodeTreap*& treapR)
{
	if (treap == nullptr)
	{
		treapL = treapR = nullptr;
	}
	else if (treap->Key <= key)
	{
		Split(treap->RightNode, key, treapL, treapR);
		treap->RightNode = treapL;
		treapL = treap;
	}
	else
	{
		Split(treap->LeftNode, key, treapL, treapR);
		treap->LeftNode = treapR;
		treapR = treap;
	}
}

NodeTreap* Treap::Merge(NodeTreap*& treapL, NodeTreap*& treapR)
{
	if (treapR == nullptr)
	{
		return treapL;
	}
	if (treapL == nullptr)
	{
		return treapR;
	}
	else if (treapL->Priority > treapR->Priority)
	{
		treapL->RightNode = Merge(treapL->RightNode, treapR);
		return treapL;
	}
	else
	{
		treapR->LeftNode = Merge(treapL, treapR->LeftNode);
		return treapR;
	}
}

void Treap::PushToQueue(NodeTreap*& queue, int* length, NodeTreap*& node)
{
	if (node->LeftNode != nullptr)
	{
		queue->LeftNode = node->LeftNode;
		length++;
	}
	if (node->RightNode != nullptr)
	{
		queue->LeftNode = node->RightNode;
		length++;
	}
}

bool Treap::Find(int key)
{
	NodeTreap* supNode;
	if (_headTreap == nullptr)
	{
		return false;
	}
	else
	{
		supNode = _headTreap;
		while (supNode != nullptr)
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

void Treap::Insert1S2M(int key, int priority)
{
	NodeTreap* left = nullptr;
	NodeTreap* right = nullptr;
	NodeTreap* nodeTreap = new NodeTreap;
	nodeTreap->Key = key;
	nodeTreap->Priority = priority;
	Split(_headTreap, key, left, right);
	_headTreap = Merge(left, nodeTreap);
	_headTreap = Merge(_headTreap, right);
}

void Treap::Insert1S(int key, int priority)
{
	NodeTreap* supNode = _headTreap;
	NodeTreap* parentNode = _headTreap;
	int dir = 0;
	if (_headTreap != nullptr)
	{
		while (supNode->Priority > priority)
		{
			if (key < supNode->Key)
			{
				parentNode = supNode;
				dir = 0;
				supNode = supNode->LeftNode;
			}
			else
			{
				dir = 1;
				parentNode = supNode;
				supNode = supNode->RightNode;
			}
			if (supNode == nullptr)
			{
				break;
			}
		}
	}
	else
	{
		_headTreap = new NodeTreap;
		_headTreap->Priority = priority;
		_headTreap->Key = key;
		return;
	}
	NodeTreap* L = nullptr;
	NodeTreap* R = nullptr;
	Split(supNode, key, L, R);
	NodeTreap* newNode = new NodeTreap;
	newNode->Key = key;
	newNode->Priority = priority;
	newNode->LeftNode = L;
	newNode->RightNode = R;

	if (supNode == _headTreap)
	{
		_headTreap = newNode;
	}
	else if (dir == 0)
	{
		parentNode->LeftNode = newNode;
	}
	else
	{
		parentNode->RightNode = newNode;
	}
}

void Treap::Remove1M(int key)
{

	if (_headTreap->Key == key && _headTreap->LeftNode == nullptr && _headTreap->RightNode == nullptr)
	{
		delete _headTreap;
		_headTreap = nullptr;
	}
	NodeTreap* supNode = _headTreap;
	NodeTreap* parentNode = _headTreap;
	int dir;
	if (_headTreap != nullptr)
	{
		while (supNode!=nullptr&&supNode->Key!=key)
		{
			if (key < supNode->Key)
			{
				parentNode = supNode;
				dir = 0;
				supNode = supNode->LeftNode;
			}
			else
			{
				dir = 1;
				parentNode = supNode;
				supNode = supNode->RightNode;
			}
		}
	}
	else
	{
		return;
	}
	if (supNode == nullptr)
	{
		return;
	}
	NodeTreap* newNode;
	newNode = Merge(supNode->LeftNode, supNode->RightNode);
	if (supNode == _headTreap)
	{
		_headTreap = newNode;
	}
	else if (dir == 0)
	{
		parentNode->LeftNode = newNode;
	}
	else
	{
		parentNode->RightNode = newNode;
	}
	delete supNode;
}

void Treap::Remove2S1M(int key)
{
	NodeTreap* L = nullptr;
	NodeTreap* L2 = nullptr;
	NodeTreap* R = nullptr;
	NodeTreap* deletednode;
	Split(_headTreap, key, L, R);
	Split(L, key - 1, L2, deletednode);
	_headTreap = Merge(L2, R);
	if (deletednode != nullptr)
	{
		delete deletednode;
	}
}