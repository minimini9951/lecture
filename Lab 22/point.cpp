#include "point.hpp"  // Point interface
#include <cmath>      // sin, cos, sqrt

namespace {
}

namespace hlp2
{
	// define 3 constructors
	Point::Point()
	{
		Point::x = 0;
		Point::y = 0;
	}

	Point::Point(double x, double y)
	{
		Point::x = x;
		Point::y = y;
	}

	Point::Point(const double* index)
	{
		Point::x = *index;
		Point::y = *(index + 1);
	}

	// define 8 member functions
	double Point::operator[](int index) const
	{
		return 
	}

	double& Point::operator[](int index)
	{
		// TODO: ���⿡ return ���� �����մϴ�.
	}

	Point& Point::operator+=(const Point& other)
	{
		// TODO: ���⿡ return ���� �����մϴ�.
	}

	Point& Point::operator+=(double num)
	{
		// TODO: ���⿡ return ���� �����մϴ�.
	}

	Point& Point::operator++()
	{
		// TODO: ���⿡ return ���� �����մϴ�.
	}

	Point Point::operator++(int)
	{
		return Point();
	}

	Point& Point::operator--()
	{
		// TODO: ���⿡ return ���� �����մϴ�.
	}

	Point Point::operator--(int)
	{
		return Point();
	}

	// define 15 non-member, non-friend functions
	Point operator%(const Point& other, double angle)
	{
		return Point();
	}

	double operator/(const Point& other1, const Point& other2)
	{
		return 0.0;
	}

	Point operator+(const Point& other1, const Point& other2)
	{
		return Point();
	}

	Point operator+(const Point& other, double num)
	{
		return Point();
	}

	Point operator+(double num, const Point& other)
	{
		return Point();
	}

	Point operator-(const Point& other1, const Point& other2)
	{
		return Point();
	}

	Point operator-(const Point& other, double num)
	{
		return Point();
	}

	Point operator-(double num, const Point& other)
	{
		return Point();
	}

	Point operator-(const Point& other)
	{
		return Point();
	}

	Point operator^(const Point& other1, const Point& other2)
	{
		return Point();
	}

	double operator*(const Point& other1, const Point& other2)
	{
		return 0.0;
	}

	Point operator*(const Point& other, double num)
	{
		return Point();
	}

	Point operator*(double num, const Point& other)
	{
		return Point();
	}

	std::ostream& operator<<(std::ostream& os, const Point& obj)
	{
		// TODO: ���⿡ return ���� �����մϴ�.
	}

	std::ifstream& operator>>(std::ifstream& ifs, Point& obj)
	{
		// TODO: ���⿡ return ���� �����մϴ�.
	}

}

// define private stuff here [if any] in this anonymous namespace ...
namespace {
}
