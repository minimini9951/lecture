#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>

struct Point {
  int x;
  int y;
};

class Shape {
private:
  int id;                  // a shape's unique id.
  std::string border;      // a shape's border color
  std::string fill;        // a shape's fill color
  static int count;        // how many shapes created?

public:

  Shape(std::string& line);

  Shape() = delete;
  Shape(Shape const&) = delete;
  Shape& operator=(Shape const&) = delete;

  virtual ~Shape();

  int getId() const;

  std::string getBorder() const;

  std::string getFill() const;

  static int getCount();

  virtual void print_details() const;

  virtual Point getCenter() const = 0;

  virtual double getArea() const = 0;

};

#endif // end #ifndef SHAPE_HPP
