#include "FunctionOverride.h"
#include <iostream>


void Override::Base::AFn()
{
	std::cout << "Base::AFn()" << std::endl;
}

void Override::Base::BFn()
{
	std::cout << "Base::BFn()" << std::endl;
}

void Override::TestOverride()
{
	Override::Base baseObj;
	Override::Derived obj;

	baseObj.AFn(); //Base.AFn();
	//baseObj.Bfn(); //CAN NOT

	obj.AFn();
	obj.BFn();

	Override::Base* basePtr = &obj;
	Override::Derived* derivedPtr = &obj;
	Override::Base* d2Ptr = &baseObj;
	//Override::Derived* d2Ptr = &baseObj;


	basePtr->AFn();
}