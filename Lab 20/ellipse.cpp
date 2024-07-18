#include "ellipse.hpp"
#include <sstream>
#include <iostream>

#define M_PI 3.14159265358979323846

int Ellipse::count = 0;

Ellipse::Ellipse(std::string& line) : Shape(line)
{
	char c;
	std::string word;
	std::istringstream iss(line);

	iss >> word >> word >> word >> center.x >> c >> center.y >> a >> b;

	++count;
}

Ellipse::~Ellipse()
{
	--count;
}

int Ellipse::getA() const
{
	return a;
}

int Ellipse::getB() const
{
	return b;
}

int Ellipse::getCount()
{
	return count;
}

void Ellipse::print_details() const
{
	Shape::print_details();
	std::cout << "Type = Ellipse Shape" << std::endl;
	std::cout << "Center = " << center.x << "," << center.y << std::endl;
	std::cout << "a-length = " << a << std::endl;
	std::cout << "b-length = " << b << std::endl;
}

Point Ellipse::getCenter() const
{
	return Point();
}

double Ellipse::getArea() const
{
	int a { getA() };
	int b { getB() };
	return a * b * M_PI;
}
