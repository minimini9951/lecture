
#include "Pair.h"

template<typename T1, typename T2>
inline Pair<T1, T2>::Pair(const T1& k, const T2& v) : key(k), value(v)
{

}

template<typename T1, typename T2>
inline bool Pair<T1, T2>::operator==(const Pair<T1, T2>& other)
{
	return ((this->key == other.key) && (this->value == other.value));
}

template<typename T1, typename T2>
inline bool Pair<T1, T2>::operator==(const T1& otherKey)
{
	return this->key == otherKey;
}

template<typename T1, typename T2>
inline bool Pair<T1, T2>::operator==(const T2& otherValue)
{
	return this->value == otherValue;;
}

template<typename T1, typename T2>
inline bool Pair<T1, T2>::operator<(const Pair<T1, T2>& other)
{
	return this->key < other.key;
}

#include <string>

template <typename T1>
inline bool Pair<T1, const char*>::operator<(const Pair<T1, const char*>& other)
{
	return strcmp()this->value, other->value;
}

template<typename T1>
inline int ABC::MultiplyByAnything(const T1& other)
{
	this->Data *= other;

	return this->Data;
}