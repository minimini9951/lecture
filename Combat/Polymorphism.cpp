#include "Polymorphism.h"
#include <iostream>

Polymorphism::A::A()
{
	std::cout << "A::A()" << std::endl;
}

Polymorphism::A::A(int i): a(i)
{
	std::cout << "A::A()" << std::endl;
}

Polymorphism::A::~A()
{
	std::cout << "A::~A()" << std::endl;
}

const Polymorphism::A Polymorphism::A::operator+(const A& other) const
{
	A res;
	res.a = this->a + other.a;

	return res;
}

const Polymorphism::A Polymorphism::A::operator+(int i) const
{
	A res;
	res.a = this->a + i;

	return res;
}

Polymorphism::B::B()
{
	std::cout << "B::B()" << std::endl;
}

Polymorphism::B::B(int i): b(i + 5), A::A(i)
{
	std::cout << "B::A(int i)" << std::endl;
}

Polymorphism::B::~B()
{
	std::cout << "B::~B()" << std::endl;
}
