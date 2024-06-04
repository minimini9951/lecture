#include <iostream>

#define num = 'a' - 'A'

void hello()
{
	std::cout << "hi" << std::endl
		<< "my name is "
		<< "Psi" << std::endl;
}

void variable() {
	//define variables
	int i = 0;
	char c = 0;
	double d = 0.0;
	float f = 0.f;

	int arr[10];
	int* parr = arr;

	int* pi = &i;
}

void forloop()
{
	// C++ for loop;
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << std::endl;
	}
	std::cout << "sum of the 1 to 10" << std::endl;

	int i, sum = 0;

	for (i = 1; i <= 10; i++)
	{
		sum += i;
	}

	std::cout << "합은 : " << sum << std::endl;
}

void whileloop()
{
	//using while
	int i = 1, sum = 0;

	while (i <= 10) {
		sum += i;
		i++;
	}

	std::cout << "합은 : " << sum << std::endl;
}

void ifelse()
{
	int lucky_number = 3;
	std::cout << "내 비밀 수를 맞추어 보세요~" << std::endl;

	int user_input;  // 사용자 입력

	while (1) {
		std::cout << "입력 : ";
		std::cin >> user_input;
		if (lucky_number == user_input) {
			std::cout << "맞추셨습니다~~" << std::endl;
			break;
		}
		else {
			std::cout << "다시 생각해보세요~" << std::endl;
		}
	}
}

int test(int* arr, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		std::cout << "old value : " << *(arr + i);
		*(arr + i) = *(arr + i) * 2;
		std::cout << " new value : " << *(arr + i) << std::endl;
		sum += *(arr + i);
	}

	return sum;
}

void solve_x(float a, float b, float c, float* x1, float* x2)
{
	*x1 = (- b + sqrt((b * b) - 4 * a * c)) / (2 * a);
	*x2 = (- b - sqrt((b * b) - 4 * a * c)) / (2 * a);
}

void find(char* dst, char* src, int size)
{
	for (int i = 0; i < size; i++)
	{
		if ((int)*(src + i) >= 'A' || (int)*(src + i) <= 'M')
		{

		}
	}
}