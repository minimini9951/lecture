#include <iostream>
#include "q.hpp"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: ./q.out input-text-file input-text-file-stats\n";
        return 0;
    }

    hlp2::q(argv[1], argv[2]);
}