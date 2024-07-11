#include <cstring>
#include <string>
#include <fstream>
#include <iostream>

std::ifstream ifs;
std::ofstream ofs;

namespace hlp2 {
  // provide definition of q here ...
    void extract(char const* filename, char const** keywords) {
        std::ifstream ifs(filename);
        if (!ifs) {
            std::cout << "File " << filename << " not found.\n";
            return;
        }

        std::string line;
        std::string previous_word;
        std::string word;
        
        while (ifs >> word) 
        {
            if (!previous_word.empty()) 
            {
                for (const char** k = keywords; *k != nullptr; ++k) 
                {
                    if (previous_word == *k) 
                    {
                        std::cout << word << ' ';
                        // word�� keyword�ȿ� �ִ� �ܾ��� ��쿡�� previous_word = word �̺κ��� ���������. �� ��� �� ����� �ұ�?
                        for (const char** j = keywords; *j != nullptr; ++j)
                        {
                            if (word == *j)
                            {
                                ifs >> word;
                                previous_word = word;
                                break;
                            }
                        }
                    }
                }
            }
            previous_word = word;
        }
        std::cout << '\n';
    }

}
