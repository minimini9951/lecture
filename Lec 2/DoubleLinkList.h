#pragma once
#include "Sorts.h"
#include <iostream> //std::iostream // std::ostream
//DO NOT MODIFY INCLUDES

class DoubleNode;



class DoubleLinkList
{
	//All data in the DoubleLinkList should be private

	DoubleNode* mHead;
	DoubleNode* mTail;
	int size;

public:

	///////////////////////
	//Constructors
	///////////////////////
	DoubleLinkList();
	DoubleLinkList(const DoubleLinkList& other);


	///////////////////////
	//Gettors
	///////////////////////
	const DoubleNode* Head() const;
	const DoubleNode* Tail() const;
	int Size() const;
	int AllocatedMemSize()const;

	
	///////////////////////
	//Node adding
	///////////////////////

	bool AddFront(DoubleNode* node);
	bool AddFront(int val);

	bool AddEnd(DoubleNode* node);
	bool AddEnd(int val);

	//This should fail if the index is invalid
	bool AddAtIndex(DoubleNode* node, int index);
	bool AddAtIndex(int val, int index);

	///////////////////////
	//Delete functions
	///////////////////////

	bool DeleteFront();
	bool DeleteEnd();
	bool DeleteAll();
	~DoubleLinkList();
	//This should fail if the index is invalid
	bool DeleteIndex(int index);


	///////////////////////
	// operators
	///////////////////////
	//This iterates
	const DoubleNode* operator[](int index) const;

	//Copies values
	DoubleLinkList& operator=(const DoubleLinkList);

	//Inserts copies of the nodes at the end
	DoubleLinkList& operator+=(const DoubleLinkList);

	//Output Operator
	//Define on your own

	//Input operator
	//Define on your own


	///////////////////////
	// Finds
	///////////////////////
	//Find
	DoubleNode* FindValue(int val);
	int FindIndex(DoubleNode* node);


	DoubleNode* FindReplace(int findVal, int replaceVal);


	///////////////////////
	// Friend functions
	///////////////////////
	friend void Sort::SortLowerFirst(DoubleLinkList* list);	//1,2,3,4,5,6,7,8,9...
	friend void Sort::SortHigherFirst(DoubleLinkList* list);	//9,8,7,6,5,4,3,2,1...
	friend void Sort::SortOddFirsts(DoubleLinkList* list);	//1,7,5,3,9,2,6,8,4

};