#include <iostream>
#include <iomanip>
#include <fstream>

class COUNT
{
public:
	int tot_count = 0;
	int blank_count = 0;
	int digit_count = 0;
	int char_count = 0;
	int other_count = 0;
	int upper = 0;
	int lower = 0;
	int sum = 0;
	int digit_count2 = 0;
	int alp_arr[26];
};

namespace hlp2 {

	class COUNT ct;

	void open_file(std::ifstream& ifs, std::ofstream& ofs, char const* input_filename, char const* analysis_file);

	void count_char(std::ifstream& ifs, class COUNT* count);

	void print_char(std::ofstream& ofs, class COUNT* count);

	void count_digit(std::ifstream& ifs, COUNT* count);

	void print_digit(std::ofstream& ofs, class COUNT* count);

	void open_file(std::ifstream &ifs, std::ofstream &ofs, char const* input_filename, char const* analysis_file)
	{
		ifs.open(input_filename);
		if (!ifs.is_open())
			std::cout << "File " << input_filename << " not found." << std::endl;

		ofs.open(analysis_file);
		if (!ofs.is_open())
			std::cout << "Unable to create output file " << analysis_file << "." << std::endl;

		ofs << "Statistics for file: " << input_filename << std::endl;
		ofs << "---------------------------------------------------------------------\n" << std::endl;
	}

	void count_char(std::ifstream &ifs, class COUNT* count)
	{
		char c;
		for (int i = 0; i < 26; i++)
		{
			count->alp_arr[i] = 0;
		}

		while (ifs.get(c))
		{
			count->tot_count++;
			if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
				count->blank_count++;
			else if (c >= '0' && c <= '9')
				count->digit_count++;
			else if (c >= 'A' && c <= 'Z')
			{
				count->char_count++;
				count->alp_arr[c - 'A']++;
				count->upper++;
			}
			else if (c >= 'a' && c <= 'z')
			{
				count->char_count++;
				count->alp_arr[c - 'a']++;
				count->lower++;
			}
			else
				count->other_count++;
		}
	}

	void print_char(std::ofstream &ofs, class COUNT* count)
	{
		ofs << "Total # of characters in file: " << count->tot_count << std::endl << std::endl;

		ofs << "Category            How many in file             % of file" << std::endl;
		ofs << "---------------------------------------------------------------------" << std::endl;
		ofs << "Letters" << std::setw(29) << count->char_count << std::setw(20) << std::fixed << std::setprecision(2) << (float)count->char_count / count->tot_count * 100 << " %" << std::endl;
		ofs << "White space" << std::setw(25) << count->blank_count << std::setw(20) << std::fixed << std::setprecision(2) << (float)count->blank_count / count->tot_count * 100 << " %" << std::endl;
		ofs << "Digits" << std::setw(30) << count->digit_count << std::setw(20) << std::fixed << std::setprecision(2) << (float)count->digit_count / count->tot_count * 100 << " %" << std::endl;
		ofs << "Other characters" << std::setw(20) << count->other_count << std::setw(20) << std::fixed << std::setprecision(2) << (float)count->other_count / count->tot_count * 100 << " %" << std::endl << std::endl << std::endl;


		ofs << "LETTER STATISTICS" << std::endl << std::endl;

		ofs << "Category            How many in file      % of all letters" << std::endl;
		ofs << "---------------------------------------------------------------------" << std::endl;
		ofs << "Uppercase" << std::setw(27) << count->upper << std::setw(20) << std::fixed << std::setprecision(2) << (float)count->upper / count->char_count * 100 << " %" << std::endl;
		ofs << "Lowercase" << std::setw(27) << count->lower << std::setw(20) << std::fixed << std::setprecision(2) << (float)count->lower / count->char_count * 100 << " %" << std::endl;

		for (int i = 0; i < 26; i++)
		{
			ofs << (char)('a' + i) << std::setw(35) << count->alp_arr[i] << std::setw(20) << std::fixed << std::setprecision(2) << (float)count->alp_arr[i] / count->char_count * 100 << " %" << std::endl;
		}
		ofs << std::endl << std::endl;
	}

	void count_digit(std::ifstream& ifs, COUNT* count) {
		char c;
		ifs.clear();
		ifs.seekg(0);
		while (ifs.get(c)) {
			if (isdigit(c)) {
				ifs.unget(); // Put the digit back to read the full number
				int value;
				ifs >> value;
				count->digit_count2++;
				count->sum += value;
			}
		}
	}

	void print_digit(std::ofstream &ofs, class COUNT* count)
	{
		ofs << "NUMBER ANALYSIS\n" << std::endl;

		ofs << "Number of integers in file:          " << std::left << count->digit_count2 << std::endl;
		ofs << "Sum of integers:                     " << std::left << count->sum << std::endl;
		if (count->digit_count2 == 0)
			count->digit_count2 = 1;
		ofs << "Average of integers:                 " << std::left << (float)count->sum / count->digit_count2 << std::endl;
		ofs << "_____________________________________________________________________" << std::endl;
	}

	void q(char const* input_filename, char const* analysis_file)
	{
		std::ifstream ifs;
		std::ofstream ofs;

		open_file(ifs, ofs, input_filename, analysis_file);

		count_char(ifs, &ct); 
		
		count_digit(ifs, &ct);

		print_char(ofs, &ct);

		print_digit(ofs, &ct);
	}
}
