#pragma once

struct SingleNode
{
	SingleNode();
	SingleNode(int data);

	int mData;
	SingleNode* pNext;
};

struct DoubleNode
{
	DoubleNode();
	DoubleNode(int data);

	int mData;
	DoubleNode* pNext;
	DoubleNode* pPrev;
};