template <typename T>
void xchange(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<int N, typename T>
auto foo(T value) -> decltype(value* N) {
	return value * N;
}

template <typename T>
int Compare(T const& a, T const& b) {
	if (a > b) {
		return 1;
	}
	else if (b > a) {
		return -1;
	}
	else {
		return 0;
	}
}

#include <cstddef>

template<typename T, std::size_t N>
constexpr std::size_t Length(T(&)[N]) noexcept {
	return N;
}

class C {
public:
	template <typename T>
	T add(const T& a, const T& b) {
		return a + b;
	}

	template <typename T>
	auto add(const T& a, const T& b) -> decltype(a + b) {
		return a + b;
	}

	template <typename T, typename U>
	auto add(const T& a, const U& b) -> decltype(static_cast<T>(a + b)) {
		return static_cast<T>(a + b);
	}
};

template <typename T>
class wrapper {
public:
	explicit wrapper(T value) : value_(value) {}

	T get() const {
		return value_;
	}

	template <typename U>
	U as() const {
		return static_cast<U>(value_);
	}

private:
	T value_;
};
