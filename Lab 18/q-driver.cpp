#include <iostream>
#include "q.hpp"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: ./q.out tsunami-data-file your-summary-output-file;\n";
        return 0;
    }

    int num_events;
    hlp2::Tsunami* tsun_data = hlp2::read_tsunami_data(argv[1], num_events);
    if (tsun_data) {
        hlp2::print_tsunami_data(tsun_data, num_events, argv[2]);
        delete[] tsun_data;
    }
}