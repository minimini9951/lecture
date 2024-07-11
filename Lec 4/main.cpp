#include <iostream>



class A
{
public:
	int i = 9;
	A() {}
	A(int i, float f) {}

	void a() { std::cout << "A"; }
	void b() { std::cout << i; }
};

class B : public A
{

public:
	int i = 20;
	void a() { std::cout << "B"; }
	void b() { A::b(); std::cout << "accessed though B"; }
	void c() { std::cout << this->i << A::i; }
};

void Test1()
{
	A a;
	A a2(1, 1.f);
	B b;
	//B b2(1, 1.f);		//Constructors not inherited
	
	a.a();
	b.a();
	
	a.b();
	b.b();
}

class C
{
public:
	void f3(int)
	{
		std::cout << "C3" << std::endl;
	}
};

class D : public C
{
public:
	void f3()
	{
		C::f3(0);
		std::cout << "D3" << std::endl;
	}
};

void Test2()
{

	
	C c;
	D d;

	c.f3(4);
	d.f3();

	d.C::f3(4);

	C* pc = &d;
	pc->f3(5);
	//pc->f3();	//Can not access D::f3(int) from a C object/class 

}
class E
{
protected:
public:
	int i = 10;
	int b = 5;
	int c = 20;

	void print()
	{
		std::cout << i << "," << b << "," << c << std::endl;
	}
};
class F : protected E
{
public:
	//int c = 77;

	void print()
	{
		i++;
		std::cout << c << std::endl;
	}
};

class G : public F
{
	void T()
	{
		i++;
	}
};

class H : private G
{

};
void Test3()
{
	E e;
	F f;
	G g;
	H h;

	e.i;
	f.i;
	g.i;

	//e.print();
	f.print();

}

int main()
{
	Test1();
	Test2();
	

	Test3();

	return 0;
}