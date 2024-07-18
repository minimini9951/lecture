#include "polygon.hpp"
#include <sstream>
#include <string>
#include <iostream>

int Polygon::count = 0;

Polygon::Polygon(std::string& line) : Shape(line)
{
	int number;
	char c;
	std::string word;
	std::istringstream iss(line);
	int x = 0;
	int y = 0;
	int ct = 0;

	iss >> word >> word >> word;
	while (iss >> number)
	{
		x = number;
		iss >> c >> number;
		y = number;
		vertices.push_back({ x, y });
	}

	++count;
}

Polygon::~Polygon()
{
	--count;
}

std::vector<Point>& Polygon::getVertices()
{
	return vertices;
}

int Polygon::getCount()
{
	return count;
}

void Polygon::print_details() const
{
	Shape::print_details();
	for (int i = 0; i < vertices.size(); ++i) {
		std::cout << vertices[i].x << "," << vertices[i].y;
		if (i < vertices.size() - 1) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

Point Polygon::getCenter() const
{
	Point centroid = { 0, 0 };
	int numVertices = (int)vertices.size();

	if (numVertices == 0) {
		return centroid;
	}

	for (const auto& vertex : vertices) {
		centroid.x += vertex.x;
		centroid.y += vertex.y;
	}

	centroid.x /= numVertices;
	centroid.y /= numVertices;

	return centroid;
}

double Polygon::getArea() const
{
	double area = 0.0;
	int numVertices = (int)vertices.size();

	for (int i = 0; i < numVertices; ++i) {
		int j = (i + 1) % numVertices;
		area += vertices[i].x * vertices[j].y;
		area -= vertices[j].x * vertices[i].y;
	}

	return std::abs(area) / 2.0;
}
