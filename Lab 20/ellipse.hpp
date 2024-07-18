#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "shape.hpp"
#include <string>

class Ellipse : public Shape {
private:
  Point center; 
  int a;   // a-length, length of the semi-major axis
  int b;   // b-length, length of the semi-minor axis
  static int count; // how many ellipses created?

public:

  Ellipse(std::string& line);

  Ellipse() = delete;
  Ellipse(Ellipse const&) = delete;
  Ellipse& operator=(Ellipse const&) = delete;

  virtual ~Ellipse();

  int getA() const;

  int getB() const;

  static int getCount();

  virtual void print_details() const override;

  virtual Point getCenter() const override;

  virtual double getArea() const override;
};

#endif // end #ifndef ELLIPSE_HPP
