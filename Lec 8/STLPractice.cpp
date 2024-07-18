
#include <vector>
#include <list>
#include <ctime>
#include <random>
#include <iostream>
#include <algorithm>

namespace STL
{
	template <typename T1> 
	T1 Add(const T1& a, const T1& b)
	{
		return a + b;
	}

	template <typename T1>
	void Print(const T1& a)
	{
		std::cout << a << std::endl;
	}

	template <typename T1, typename T2>
	void Print(const std::pair<T1, T2& a)
	{
		std::cout << a.first << " " << a.second << std::endl;
	}

	template<typename T1>
	void Set(T1& val, const T1& newVal)
	{
		val = newVal;
	}

	template<typename T1, typename T2>
	void Set(std::pair<T1, T2>& val, const std::pair<T1, T2>& newVal)
	{
		val.first = newVal.first;
		val.second = newVal.second;
	}

	template <typename T2>
	void AddAll(std::vector<T2>& a)
	{
		if (a.empty())
			return;

		//std::vector<int>::iterator iter1 = vector.begin();
		//std::list<int>::iterator iter2 = list.begin();
		auto res = *(a.begin());	//The compiler will deduce the type of my value, depending on what *(a.begin()) return type is

		auto iter = a.begin();
		iter++;
		for (auto iter = a.begin() +1; iter != a.end())
		{
			res = Add(res, *iter);
		}
	}

	int RandomNumber(int min, int max)
	{
		return (std::rand() % (max - min)) + min;
	}

	void Print(int i)
	{
		std::cout << i << " ";
	}

	void STL2()
	{
		class A
		{
			int data[100];
			std::vector<int> moreData;
		public:
			A() : data;
			A(const A&);
			~A()
			{
			}
		};
		std::srand(std::time(0));

		std::vector<int> vec;

		for (int i = 0; i < 10; i++)
			vec.push_back(RandomNumber(5, 10));

		std::for_each(vec.begin(), vec.end(), Print);

		std::list<int> lst;
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			lst.push_back(RandomNumber(5, 10));

		std::for_each(lst.begin(), lst.end(), Print);

		//Sorting
		std::sort(vec.begin(), vec.end());		//bool int::operator<(int)
		//std::sort(lst.begin(), lst.end());	//DOES NOT COMPILE
		lst.sort();								//bool int::operator<(int)
		//vec.sort();							//vector<int>::sort DOES NOT EXIST

		std::for_each(vec.begin(), vec.end(), Print);

		std::cout << std::endl;

		std::for_each(lst.begin(), lst.end(), Print);

		vec.shrink_to_fit();

		int* p = &vec.at(9);

		vec.insert(vec.begin() + 5, 10);

		(*p)++;
	}
}

int main()
{
	STL::STL2();
}