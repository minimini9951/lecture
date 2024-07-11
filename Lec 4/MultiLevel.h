#pragma once

namespace MultiLevel
{
	class Base
	{
	protected:
		int data;
	public:
		void BaseFn();
	};

	class Derived : public Base
	{
	private:
		int DerivData;
		//protected int Base::data
		//public void Base::BaseFn()
	};

	class SuperDerived : public Derived
	{
	public:
		int SuperDerivedData;
		//protected int Base::data
		//public void Base::BaseFn()
	};


}