#pragma once

//Simple Inheritance

class Base //base parent class
{
private:
	int a;
protected:
	int p;
public:
	int c;
	void AFn() {};
};

class Derived : public Base //Derived IS a Base with some custom data/fn
{
	//Base::a exist. But it is not accessible
protected:
	//Base::p;
private:
	int b;
public:
	void BFn();
	//void Base::Afn();
};

void TestSimpleInherit();