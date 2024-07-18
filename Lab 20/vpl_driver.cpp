#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "shape.hpp"
#include "ellipse.hpp"
#include "polygon.hpp"
#include "process.hpp"

static void print_all(std::vector<Shape*> const&);
static void print_polygon(std::vector<Shape*> const&);
static void print_ellipse(std::vector<Shape*> const&);

int main(int argc, char *argv[])
{

  int output_type {1}; // 출력할 모양을 결정할 변수 선언

  if (argc == 1) 
    std::cin >> output_type;
  else if (argc == 2) 
    output_type = std::stoi(std::string(argv[1]));

  output_type = (output_type < 1) ? 1 : (output_type > 4) ? 4 : output_type;

  // 파일열기 오류처리
  std::ifstream ifs{"shapes.txt"};
  if (!ifs) {
    std::cerr << "Unable to open input file shapes.txt!!!\n";
    return 0;
  }

  // parse file and populate containers with pointers to derived class objects
  std::vector<Shape*> vs;  // container for (pointers to) all shapes (모든 도형)
  std::vector<Shape*> ves; // container for (pointers to) ellipses (타원)
  std::vector<Shape*> vps; // container for (pointers to) polygons (다각형)

  //파일의 내용에 따라서 ves, vps로 분리 (vs = ves + vps)
  parse_file(ifs, vs, ves, vps);

  // 도형 총 갯수 출력
  std::cout << "Total number of shapes in file         = "
            << Shape::getCount() << "\n";
  // 타원 총 갯수 출력
  std::cout << "Total number of ellipse shapes in file = "
            << Ellipse::getCount() << "\n";
  // 다각형 총 갯수 출력
  std::cout << "Total number of polygon shapes in file = "
            << Polygon::getCount() << "\n\n";
  
  switch (output_type) {
    case 1: print_ellipse(ves); break;
    case 2: print_polygon(vps); break;
    case 3: print_all(vs); break;
    case 4: print_all(vs); print_ellipse(ves); print_polygon(vps); break;
  }

  cleanup(vs, ves, vps);
}

// print all information about shapes in course
static void print_all(std::vector<Shape*> const& vs) {
  std::cout << "SHAPE INFORMATION" << "\n";
  std::cout << "---------------------------------" << "\n";
  print_records(vs);

  std::cout << "SHAPE STATISTICS" << "\n";
  std::cout << "--------------------------------" << "\n";
  print_stats(vs);
}

static void print_ellipse(std::vector<Shape*> const& ves) {
  std::cout << "ELLIPSE SHAPE INFORMATION" << "\n";
  std::cout << "---------------------------------" << "\n";
  print_records(ves);

  std::cout << "ELLIPSE SHAPE STATISTICS" << "\n";
  std::cout << "--------------------------------" << "\n";
  print_stats(ves);
}

static void print_polygon(std::vector<Shape*> const& vps) {
  std::cout << "POLYGON SHAPE INFORMATION" << "\n";
  std::cout << "----------------------------" << "\n";
  print_records(vps);

  std::cout << "POLYGON SHAPE STATISTICS" << "\n";
  std::cout << "--------------------------------" << "\n";
  print_stats(vps);
}
