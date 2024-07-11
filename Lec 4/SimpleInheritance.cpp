#include "SimpleInheritance.h"
#include "FunctionOverride.h"

void TestSimpleInherit()
{
	Base baseObj;
	Derived obj;

	obj.AFn(); //Can access the public fn Base::AFn
	obj.BFn(); //Can access the public fn Derived::BFn

	baseObj.AFn();
	//baseObj.BFn(); //Can not access Derived::BFn as baseObj IS NOT a Derive class

	baseObj.c;
	obj.c;
}

void Derived::BFn()
{
	this->b;   //
	this->p;   //
	this->c;   //
	//this->a; //CAN NOT access parent class privates
}
