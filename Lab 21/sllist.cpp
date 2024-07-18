#include "sllist.hpp"

namespace hlp2
{
	struct node 
	{
		int value;
		node* next;
	};

	struct sllist 
	{
		node* head;
	};

	int data(node const* p) { return p->value; }

	void data(node* p, int newval) { p->value = newval; }

	node* next(node* p) { return p->next; }

	node const* next(node const* p) { return p->next; }

	sllist* construct() 
	{
		return new sllist{ nullptr };
	}

	void destruct(sllist* ptr_sll) 
	{
		node* current = ptr_sll->head;
		while (current != nullptr) 
		{
			node* next = current->next;
			delete current;
			current = next;
		}
		delete ptr_sll;
	}

	bool empty(sllist const* ptr_sll) 
	{
		return ptr_sll->head == nullptr;
	}

	node* create_node(int value, node* next = nullptr) 
	{
		return new hlp2::node{ value, next };
	}

	void push_front(sllist* ptr_sll, int value) 
	{
		ptr_sll->head = create_node(value, ptr_sll->head);
	}

	void push_back(sllist* ptr_sll, int value) 
	{
		node* new_node = new node{ value, nullptr };
		if (ptr_sll->head == nullptr) 
		{
			ptr_sll->head = new_node;
		}
		else 
		{
			node* current = ptr_sll->head;
			while (current->next != nullptr) 
			{
				current = current->next;
			}
			current->next = new_node;
		}
	}

	void remove_first(sllist* ptr_sll, int value) 
	{
		node* current = ptr_sll->head;
		node* previous = nullptr;
		while (current != nullptr && current->value != value) 
		{
			previous = current;
			current = current->next;
		}
		if (current != nullptr) 
		{
			if (previous == nullptr) 
			{
				ptr_sll->head = current->next;
			}
			else 
			{
				previous->next = current->next;
			}
			delete current;
		}
	}

	void insert(sllist* ptr_sll, int value, size_t index) 
	{
		node* new_node = new node{ value, nullptr };
		if (index == 0) 
		{
			new_node->next = ptr_sll->head;
			ptr_sll->head = new_node;
			return;
		}
		node* current = ptr_sll->head;
		size_t current_index = 0;
		while (current->next != nullptr && current_index < index - 1) 
		{
			current = current->next;
			++current_index;
		}
		if (current->next != nullptr) 
		{
			new_node->next = current->next;
			current->next = new_node;
		}
		else
		{
			current->next = new_node;
		}
	}

	node const* front(sllist const* ptr_sll) 
	{
		return ptr_sll->head;
	}

	node* find(sllist const* ptr_sll, int value) 
	{
		node* current = ptr_sll->head;
		while (current != nullptr) 
		{
			if (current->value == value) 
			{
				return current;
			}
			current = current->next;
		}
		return nullptr;
	}

	size_t size(sllist const* ptr_sll) 
	{
		size_t cnt{};
		for (node* head = ptr_sll->head; head; head = next(head)) 
		{
			++cnt;
		}
		return cnt;
	}

	node* front(sllist* ptr_sll) 
	{
		return ptr_sll->head;
	}

}