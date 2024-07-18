#pragma once

//T1 requirements
// Copy Constructor
// operator==
// operator<
//T2 requirements
// Copy Constructor
//

template <typename T1, typename T2>
class Pair
{
	T1 key;
	T2 value;

public:
	Pair(const T1& k, const T2& v);

	bool operator==(const Pair<T1, T2>& other);
	bool operator==(const T1& otherKey);
	bool operator==(const T2& otherValue);
	bool operator<(const Pair<T1, T2>& other);
};

template <typename T1>
class Pair<T1, const char*>
{
	bool operator==(const T1& otherKey);
	bool operator<(const T2& other);
};

template <typename T1>
class StrPair : public Pair<T1, char*>
{
	strPair(const StrPair& other) = delete;
	StrPair& operator=(const Strpair& other) = delete;
};

class ABC
{
	int Data;

public:
	ABC(int i = 1) : Data(i) {}
	int GetData() { return Data; }

	template <typename T1>
	int MultiplyByAnything(const T1& other);
};
#include "Pair.inl"
