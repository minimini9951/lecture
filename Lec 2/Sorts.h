#pragma once
//DO NOT MODIFY INCLUDES

class SingleLinkList;
class DoubleLinkList;

namespace Sort
{
	///////////////////////
	// Sorts
	///////////////////////
	void SortLowerFirst(SingleLinkList* list);	//1,2,3,4,5,6,7,8,9...
	void SortHigherFirst(SingleLinkList* list);	//9,8,7,6,5,4,3,2,1...
	void SortOddFirsts(SingleLinkList* list);	//1,7,5,3,9,2,6,8,4
												//Sorts Odd Numbers first, in the found order
												//Then the Even numbers, in the found order
												//MAKE A HELPER FUNCTION FOR THIS

	void SortLowerFirst(DoubleLinkList* list);	//1,2,3,4,5,6,7,8,9...
	void SortHigherFirst(DoubleLinkList* list);	//9,8,7,6,5,4,3,2,1...
	void SortOddFirsts(DoubleLinkList* list);	//1,7,5,3,9,2,6,8,4
												//Sorts Odd Numbers first, in the found order
												//Then the Even numbers, in the found order
												//MAKE A HELPER FUNCTION FOR THIS
}