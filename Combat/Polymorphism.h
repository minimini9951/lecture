#pragma once

namespace Polymorphism
{
	class A
	{
		int a;
	public:
		A();
		A(int a);

		virtual ~A();

		const A operator+(const A& other) const;

		//const A& operator+=(const A& other) const;

		const A operator+(int i) const;

		//const A& operator+=(int i) const;

		void AFn();
		virtual void BFn();
	};

	class B : public A
	{
		int b;
	public:
		B();
		B(int b);

		~B();
		void AFn();
		void BFn() override;
	};

	class C : public A
	{
	public:
		C();
		void AFn();
	};

	void TestPolymorthism();
}