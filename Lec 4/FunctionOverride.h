#pragma once

namespace Override
{
	//Parent
	class Base
	{
	public:
		void AFn();
	private:
		void BFn();
	};
	//Child
	class Derived : public Base
	{
	public:
		void AFn();
		void BFn();
	};
	//Test fn
	void TestOverride();
}