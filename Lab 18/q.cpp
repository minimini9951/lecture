// This file can only have these 5 files included and therefore you should not
// remove the following include directives nor provide additional include directives!!!

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "q.hpp" // compiler needs definition of type Tsunami

// anonymous namespace for any helper functions that you wish to implement
namespace {

}

namespace hlp2 {
    Tsunami* read_tsunami_data(const std::string& file_name, int& max_cnt)
    {
        std::ifstream ifs{ file_name };
        if (!ifs.is_open())
            return nullptr;

        std::string line;
        while (std::getline(ifs, line))
        {

        }
    }

	void print_tsunami_data(const Tsunami* arr, int size, const std::string& file_name)
	{
	}
	// provide definitions of functions declared in q.hpp here ...
}