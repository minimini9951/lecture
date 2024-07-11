#include "Nodes.h"

SingleNode::SingleNode(): mData(0), pNext(nullptr)
{
}

SingleNode::SingleNode(int data): mData(data), pNext(nullptr)
{
}

DoubleNode::DoubleNode(): mData(0), pNext(nullptr), pPrev(nullptr)
{
}

DoubleNode::DoubleNode(int data): mData(data), pNext(nullptr), pPrev(nullptr)
{
}