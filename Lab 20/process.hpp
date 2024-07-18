#ifndef PROCESS_HPP
#define PROCESS_HPP

#include "shape.hpp"
#include "ellipse.hpp"
#include "polygon.hpp"
#include <fstream>
#include <vector>

void parse_file(std::ifstream& ifs,
                std::vector<Shape*>& vs,
                std::vector<Shape*>& ves,
                std::vector<Shape*>& vps);

/**
* @brief Use dynamic-binding (run-time polygmorphism) to print details of
*        shapes represented in std::vector<Shape*> container.
*
* @param vs Read-only reference to std::vector<Shape*>.
*/
void print_records(std::vector<Shape*> const& vs);

/**
* @brief Computes and prints following statistics: shape count; mean of
*        total areas; and sorted list of shapes in ASCENDING order using 
*        a shape's area as sorting criterion with each line  
*        consisting of the following information:
*        shape id, center, area.
*
* @param vs Read-only reference to vector<Shape*> for which statistics
*                 are to be computed.
*/
void print_stats(std::vector<Shape*> const& vs);

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
void cleanup(std::vector<Shape*>& vs, 
             std::vector<Shape*>& ves,
             std::vector<Shape*>& vps);

#endif // end #ifndef PROCESS_HPP
