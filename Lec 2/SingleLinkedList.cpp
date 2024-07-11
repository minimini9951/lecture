#include "SingleLinkedList.h"
#include "Nodes.h"
#include <stdio.h>

SingleLinkList::SingleLinkList(): mHead(), mTail(nullptr), size(0)
{
}

SingleLinkList::SingleLinkList(const SingleLinkList& other): mHead(nullptr), mTail(nullptr), size(0)
{
}

const SingleNode* SingleLinkList::Head() const
{
	return mHead;
}

const SingleNode* SingleLinkList::Tail() const
{
	return mTail;
}

int SingleLinkList::Size() const
{
	return size;
}

int SingleLinkList::AllocatedMemSize() const
{
	return size * 8; //?
}

void SingleLinkList::AddFront(SingleNode* node)
{
	if (mHead == nullptr)
	{
		mHead = node;
		mTail = node;
		size++;
	}
	else
	{
		SingleNode* o_head = mHead;
		mHead = node;
		mHead->pNext = o_head;
		size++;
	}
}

void SingleLinkList::AddFront(int val)
{
	SingleNode* temp = 0; //?
	temp->mData = val;
	temp->pNext = nullptr;
	if (mHead == nullptr)
	{
		mHead = temp;
		mTail = temp;
		size++;
	}
	else
	{
		SingleNode* o_head = mHead;
		temp->pNext = o_head;
		mHead = temp;
		size++;
	}
}

void SingleLinkList::AddEnd(SingleNode* node)
{
	if (mTail == nullptr)
	{
		mHead = node;
		mTail = node;
		size++;
	}
	else
	{
		mTail->pNext = node;
		mTail = node;
		size++;
	}
}

void SingleLinkList::AddEnd(int val)
{
	SingleNode* temp = 0; //?
	temp->mData = val;
	temp->pNext = nullptr;
	if (mTail == nullptr)
	{
		mHead = temp;
		mTail = temp;
		size++;
	}
	else
	{
		mTail->pNext = temp;
		mTail = temp;
		size++;
	}
}

bool SingleLinkList::AddAtIndex(SingleNode* node, int index)
{
	int i;
	SingleNode* pList = 0;
	if (pList == 0)
		pList = mHead;

	SingleNode* temp = pList;
	for (i = 0; i < index; i++)
	{
		temp = temp->pNext;
	}
	temp->pNext = node;
	temp = temp->pNext;
	node->pNext = temp;
	
}

bool SingleLinkList::AddAtIndex(int val, int index)
{
	int i;
	//
	//SingleNode n_node = SingleNode::SingleNode(val);
	//SingleNode* node = &n_node;
	//
	
	//
	SingleNode* node;
	node->mData = val;
	node->pNext = nullptr;
	//

	SingleNode* pList = 0;
	if (pList == 0)
		pList = mHead;

	SingleNode* temp = pList;
	for (i = 0; i < index; i++)
	{
		temp = temp->pNext;
	}
	temp->pNext = node;
	temp = temp->pNext;
	node->pNext = temp;
}

bool SingleLinkList::DeleteFront()
{
	SingleNode* pList = mHead;
	SingleNode* temp;
	while (pList)
	{
		temp = pList->pNext;
		delete pList;
		pList = temp;
	}
}

bool SingleLinkList::DeleteEnd()
{
	SingleNode* pList = mTail;
	SingleNode* temp;
	while (mTail)
	{

	}
}

bool SingleLinkList::DeleteAll()
{
	return false;
}
