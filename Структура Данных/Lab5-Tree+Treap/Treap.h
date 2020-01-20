#pragma once
#include "TreapNode.h"

struct Treap
{
private:
	NodeTreap* Merge(NodeTreap*& treapL, NodeTreap*& treapR);
	void Split(NodeTreap*& treap, int key, NodeTreap*& treapL, NodeTreap*& treapR);
	void PushToQueue(NodeTreap*& queue,int* length,NodeTreap*&node);
public:
	Treap();
	~Treap();
	NodeTreap* _headTreap;
	bool Find(int key);
	void Insert1S2M(int key, int priority);
	void Insert1S(int key, int priority);
	void Remove1M(int key);
	void Remove2S1M(int key);
};

