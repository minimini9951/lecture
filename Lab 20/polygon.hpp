#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "shape.hpp"
#include <iostream>
#include <vector>

class Polygon : public Shape {
private:
  std::vector<Point> vertices; // Polygon has vertices
  static int count;    // how many polygons created?

public:

  Polygon(std::string& line);

  Polygon() = delete;
  Polygon(Polygon const&) = delete;
  Polygon& operator=(Polygon const&) = delete;

  virtual ~Polygon(); 

  std::vector<Point> & getVertices();

  static int getCount();

  virtual void print_details() const override;

  virtual Point getCenter() const override;

  virtual double getArea() const override;
};

#endif // end of #ifndef POLYGON_HPP
