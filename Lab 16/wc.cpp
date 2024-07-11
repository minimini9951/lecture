
#include <iostream>
#include <iomanip>
#include <fstream>

// This is an anonymous namespace - i.e., a namespace with no name.
// Anonymous namespaces are used by C++ programmers to make names declared at global scope private to this source file:
namespace {
  const size_t MAX_LINE_LEN {2048};
}

namespace hlp2 {
	void wc(int argc, char* argv[])
	{
		int i = 0;
		std::ifstream ifs;
		//initialize total line, word, and byte counters
		int total_line;
		int line_counter = 0;
		int word;
		int byte;
		int blank = 0;
		char line[MAX_LINE_LEN];
		while (argv[i] != '\0');
		{
			ifs.open(argv[i]);
			while (ifs.getline(line, MAX_LINE_LEN - 1))
			{
				
				if ()
				{
					byte = ifs.gcount();
				}
				line_counter++;
			}
			i++;

			total_line = line_counter;
			
			blank = 0;
		}
		//	end for each line in file
		ifs.close();
		//	print line, word, and byte counts in pretty tabular format
		//	update total line, word, and byte counters
		//	end for each file specified in argv
		//	print total line, word, and byte counters in pretty tabular format
	}
}
