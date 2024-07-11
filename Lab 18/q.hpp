#ifndef Q_HPP
#define Q_HPP

// This file can have only one include directive ...

// required since type Tsunami has data member of type std::string
#include <string> // don't remove

namespace hlp2 {
  
    struct Tsunami{
        short int month;
        short int day;
        int year;
        int death_count;
        float height;
        std::string position;
    };
  
  // declaration of interface functions ...
  Tsunami* read_tsunami_data(std::string const& file_name, int& max_cnt);
  void print_tsunami_data(Tsunami const* arr, int size, std::string const& file_name);
  
} // end namespace hlp2
#endif
