// TODO: File documentation block required

// TODO: DO NOT INCLUDE any C standard library headers

#ifndef Q_H
#define Q_H

#undef max
#undef min

enum 
{
	A_GRADE = 0,
	B_GRADE = 1,
	C_GRADE = 2,
	D_GRADE = 3,
	F_GRADE = 4,
	TOT_GRADE = 5
};

double* read_data(char const* file_name, int* ptr_cnt);

double max(double const* begin, double const* end);
double min(double const* begin, double const* end);

double average(double const* begin, double const* end);
double variance(double const* begin, double const* end);
double std_dev(double const* begin, double const* end);
double median(double* base, int size);

void selection_sort(double* base, int size);
double count_grade(double const* begin, double const* end, double* ltr_grades, char alp);
void ltr_grade_pctg(double const* begin, double const* end, double* ltr_grades);
int find_min_pos(double const* begin, double const* end);

#endif // #ifndef Q_H
