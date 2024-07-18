
#include <cstddef>

namespace hlp2
{
	struct node;
	struct sllist;

	int data(node const* p);
	void data(node* p, int newval);
	node* next(node* p);
	node const* next(node const* p);

	sllist* construct();
	void destruct(sllist* ptr_sll);
	bool empty(sllist const* ptr_sll);
	size_t size(sllist const* ptr_sll);
	void push_front(sllist* ptr_sll, int value);
	void push_back(sllist* ptr_sll, int value);
	void remove_first(sllist* ptr_sll, int value);
	void insert(sllist* ptr_sll, int value, size_t index);
	node* front(sllist* ptr_sll);
	node const* front(sllist const* ptr_sll);
	node* find(sllist const* ptr_sll, int value);

}