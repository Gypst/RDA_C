#pragma once
struct NodeTreap
{
	int Key;
	int Priority;
	NodeTreap* LeftNode = nullptr;
	NodeTreap* RightNode = nullptr;
};