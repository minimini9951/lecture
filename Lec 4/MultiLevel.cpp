#include "MultiLevel.h"
#include <iostream>

void MultiLevel::TestMultiLevel()
{
	MultiLevel::Base base;
	MultiLevel::Derived derived;
	MultiLevel::SuperDerived super;

	base.BaseFn();
	derived.BaseFn();
	super.BaseFn();

	std::cout << sizeof(base) << std::endl;
	std::cout << sizeof(derived) << std::endl;
	std::cout << sizeof(super) << std::endl;
}