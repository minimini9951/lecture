#ifndef POINT_HPP
#define POINT_HPP

#define M_PI 3.14159265358979323846  /* pi */

#include <iostream>

namespace hlp2 
{
	class Point 
	{
		public:
			// declare constructors (3)
			Point();
			Point(double x, double y);
			Point(const double* index);

			// declare overloaded operators (8 member functions)
			// []
			double operator[](int index) const;
			double& operator[](int index);
			// +=
			Point& operator+=(const Point& other);
			Point& operator+=(double num);
			// ++
			Point& operator++();
			Point operator++(int);
			// --
			Point& operator--();
			Point operator--(int);
		private:
			double x; // The x-coordinate of a Point
			double y; // The y-coordinate of a Point
	};
  
	// declare 15 non-member, non-friend functions 
	// %
	Point operator%(const Point& other, double angle);
	// /
	double operator/(const Point& other1, const Point& other2);
	// + / -
	Point operator+(const Point& other1, const Point& other2);
	Point operator+(const Point& other, double num);
	Point operator+(double num, const Point& other);
	Point operator-(const Point& other1, const Point& other2);
	Point operator-(const Point& other, double num);
	Point operator-(double num, const Point& other);
	// -
	Point operator-(const Point& other);
	// ^
	Point operator^(const Point& other1, const Point& other2);
	// *
	double operator*(const Point& other1, const Point& other2);
	// *
	Point operator*(const Point& other, double num);
	Point operator*(double num, const Point& other);
	// <<
	std::ostream& operator<<(std::ostream& os, const Point& obj);
	// >>
	std::ifstream& operator>>(std::ifstream& ifs, Point& obj);
}

#endif
