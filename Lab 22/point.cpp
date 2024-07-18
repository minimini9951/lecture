#include "point.hpp"  // Point interface
#include <cmath>      // sin, cos, sqrt
#include <iostream>

namespace {
}

namespace hlp2
{
	// define 3 constructors
	Point::Point() : x{ 0 }, y{ 0 } {}

	Point::Point(double x1, double y1) : x{x1}, y{y1} {}

	Point::Point(const double* index) : x{ index[0] }, y{ index[1] } {}

	// define 8 member functions
	double Point::operator[](int index) const
	{
		if (index == 0)
		{
			return x;
		}
		else
		{
			return y;
		}
	}

	double& Point::operator[](int index)
	{
		if (index == 0)
		{
			return x;
		}
		else
		{
			return y;
		}
	}

	Point& Point::operator+=(const Point& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Point& Point::operator+=(double num)
	{
		x += num;
		y += num;
		return *this;
	}

	Point& Point::operator++()
	{
		++x;
		++y;
		return *this;
	}

	Point Point::operator++(int)
	{
		Point temp(*this);
		++(*this);
		return temp;
	}

	Point& Point::operator--()
	{
		--x;
		--y;
		return *this;
	}

	Point Point::operator--(int)
	{
		Point temp(*this);
		--(*this);
		return temp;
	}

	// define 15 non-member, non-friend functions
	Point operator%(const Point& other, double angle)
	{
		double radians = angle * M_PI / 180.0;
		double sin_angle = std::sin(radians);
		double cos_angle = std::cos(radians);
		return Point{
			other[0] * cos_angle - other[1] * sin_angle,
			other[0] * sin_angle + other[1] * cos_angle
		};
	}

	double operator/(const Point& other1, const Point& other2)
	{
		return std::sqrt((other2[0] - other1[0]) * (other2[0] - other1[0]) + (other2[1] - other1[1]) * (other2[1] - other1[1]));
	}

	Point operator+(const Point& other1, const Point& other2)
	{
		return Point{ other1[0] + other2[0], other1[1] + other2[1] };
	}

	Point operator+(const Point& other, double num)
	{
		return Point{ other[0] + num, other[1] + num };
	}

	Point operator+(double num, const Point& other)
	{
		return Point{ num + other[0], num + other[1] };
	}

	Point operator-(const Point& other1, const Point& other2)
	{
		return Point{ other1[0] - other2[0], other1[1] - other2[1] };
	}

	Point operator-(const Point& other, double num)
	{
		return Point{ other[0] - num, other[1] - num };
	}

	Point operator-(double num, const Point& other)
	{
		return Point{ num - other[0], num - other[1] };
	}

	Point operator-(const Point& other)
	{
		return Point{ -other[0], -other[1] };
	}

	Point operator^(const Point& other1, const Point& other2)
	{
		return Point{ (other1[0] + other2[0]) / 2, (other1[1] + other2[1]) / 2 };
	}

	double operator*(const Point& other1, const Point& other2)
	{
		return other1[0] * other2[0] + other1[1] * other2[1];
	}

	Point operator*(const Point& other, double num)
	{
		return Point{ other[0] * num, other[1] * num };
	}

	Point operator*(double num, const Point& other)
	{
		return Point{ num * other[0], num * other[1] };
	}

	std::ostream& operator<<(std::ostream& os, const Point& obj)
	{
		os << "(" << obj[0] << ", " << obj[1] << ")";
		return os;
	}

	std::istream& operator>>(std::istream& is, Point& obj)
	{
		is >> obj[0] >> obj[1];
		return is;
	}
}

// define private stuff here [if any] ian this anonymous namespace ...
namespace {
}
