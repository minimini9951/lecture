#include "Nodes.h"
#include "SingleLinkedList.h"
#include "DoubleLinkList.h"

int main()
{
	SingleLinkList s1;

	s1.AddFront(4);
	s1.AddFront(2);
	s1.AddFront(s1.Tail());

	s1.AddFront(&SingleNode(5));

	return 0;
}