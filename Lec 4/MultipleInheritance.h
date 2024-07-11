#pragma once

namespace MultipleInheritance
{
	class Base
	{
	protected:
		int data;
	public:
		void BasFn() {};
	};

	class Derived_A : public Base
	{
	public:
		void DerivedAFn() {};
	};

	class Derived_B : public Base
	{
	public:
		void DerivedBFn() {};
	};
}