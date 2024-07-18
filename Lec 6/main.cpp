
class Singleton
{
	//Singleton
		//Special class where only 1 object of it can exist at a time

	//How do we do it
		//Hide constructors
private:
	Singleton() = default; //Default constructor with synthesised behaviour
	Singleton(const Singleton& other) = delete; //Copy constructor does not exist anymore
	const Singleton& operator=(const Singleton& other) = delete; //Assignment Operator does not exist anymore
	~Singleton() = default; //Destructor with synthesised behaviour

		//
		//Function that can be access from outside to access the single object
	static Singleton* THESingletonPtr;

public:
	static Singleton* GetSingletonPtr()
	{
		if (THESingletonPtr == nullptr)
		{
			THESingletonPtr = new Singleton;
		}

		return THESingletonPtr;
	}

	static void DestroyPtr()
	{
		if (THESingletonPtr != nullptr)
		{
			delete THESingletonPtr;
		}

		THESingletonPtr = nullptr;
	}
};

class A
{
public:
	bool operator<(i)
	{
		return true;
	}
};

void Test1()
{
	int i1 = Max<int, int, int>(3, 4);
	int i2 = Min<int, int, int>(3, 4);

	int i3 = Max<double, float, int>(3.0, 4.0f);
	int i4 = Min<int, double, float>(3.0, 4.0f);

	int i5 = Max<int>(3.0, 4.0f);
	int i6 = Min<int>(3.0, 4.0f);
}

template <typename T1, typename T2, typename T3>
T3 Max(T1 a, T2 b)
{
	return a > b ? a : b;
}

template <typename T1, typename T2, typename T3>
T1 Min(T2 a, T3 b)
{
	return a < b ? a : b;
}

int main()
{
	Test1();

	return 0;
}