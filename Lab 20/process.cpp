#include "process.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <set>

void parse_file(std::ifstream &ifs, std::vector<Shape*>& vs,
                std::vector<Shape*>& ves, std::vector<Shape*>& vps) {
	std::string line;
	while (std::getline(ifs, line))
	{
		char c = line[0];
		line = line.substr(2);
		if (c == 'E')
		{
			Shape* p = new Ellipse(line);
			vs.push_back(p);
			ves.push_back(p);
		}
		else if (c == 'P')
		{
			Shape* p = new Polygon(line);
			vs.push_back(p);
			vps.push_back(p);
		}
		else
			break;
	}
}

void print_records(std::vector<Shape*> const& vs) {
	for (int i = 0; i < vs.size(); i++)
	{
		vs[i]->print_details();
	}
}

bool compare(Shape* a, Shape* b) {
	return a > b;
}

void print_stats(std::vector<Shape*> const& vs) {
	std::cout << "Number of shapes = " << vs.size() << std::endl;
	double sum = 0;
	std::vector<Shape*> copy = vs;
	for (int i = 0; i < vs.size(); i++)
	{
		sum += vs[i]->getArea();
	}
	std::cout << "The mean of the areas = " << sum / vs.size();
	std::cout << "The sorted list of shapes (id,center,area) in ascending order of areas:" << std::endl;
	std::sort(copy.begin(), copy.end(), compare);
	for (int i = 0; i < vs.size(); i++)
	{
		std::cout << vs[i]->getId() << "," << vs[i]->getCenter().x << "," << vs[i]->getCenter().y << "," << vs[i]->getArea() << std::endl;
	}
}
/**
* @brief Return memory allocated by operator new ONLY using pointers contained
* in container specified by first parameter. Why? Because containers specified
* in the next two containers reference the same memory locations as elements of
* first container, double deletion will cause undefined run-time behavior.
* Next, clear contents of all 3 containers.
*
* @param vs Reference to vector<Shape*> containing pointers to all shapes.
* @param ves Reference to vector<Shape*> containing pointers to ellipses.
* @param vps Reference to vector<Shape*> containing pointers to polygons.
*/
void cleanup(std::vector<Shape*>& vs, std::vector<Shape*>& ves, std::vector<Shape*>& vps) {
  // delete memory previously allocated by operator new
  for (Shape *ps : vs)
    delete ps;

  // avoid double deletion!!!
  vs.clear();
  ves.clear();
  vps.clear();
}
