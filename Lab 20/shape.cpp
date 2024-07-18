#include "shape.hpp"
#include <sstream>
#include <iostream>

int Shape::count = 0;

Shape::Shape(std::string& line) {
    std::string word;
    std::istringstream iss(line);

    iss >> word >> border >> fill;

    ++count;
    id = count;
}

Shape::~Shape()
{
	--count;
}

int Shape::getId() const
{
	return id;
}

std::string Shape::getBorder() const
{
	return border;
}

std::string Shape::getFill() const
{
	return fill;
}

int Shape::getCount()
{
	return count;
}

void Shape::print_details() const
{
	std::cout << "Id = " << id << std::endl;
	std::cout << "Border = " << border << std::endl;
	std::cout << "Fill = " << fill << std::endl;
}
