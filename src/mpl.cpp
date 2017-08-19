#include <type_traits>
#include <tuple>
#include <iostream>
#include "mpl_custom_list.hpp"

template<class T1, class T2>
inline void assert_same_type(T1, T2) { 
	T1{} = T2{}; 
}

int main() {
	static_assert(
		mpl_custom::size<std::tuple<int, float, char, void>>::value == 4, ""
	);
	assert_same_type(
		mpl_custom::list<int, float, double>{}, 
		mpl_custom::push_back<mpl_custom::list<int, float>, double>{}
	);
	assert_same_type(
		mpl_custom::list<int, char, float>{}, 
		mpl_custom::change<std::tuple<int, char, float>, mpl_custom::list>{}
	);
	assert_same_type(
		std::tuple<char, int, float, int, float>{}, 
		mpl_custom::push_front<std::tuple<int, float>, char, int, float>{}
	);
	assert_same_type(
		mpl_custom::apply<std::tuple<char, int, float>, mpl_custom::add_pointer>{},
		std::tuple<char *, int *, float *>{}
	);
	static_assert(
		mpl_custom::contains<std::tuple<char, int, float>, float>::value, ""
	);
	static_assert(
		mpl_custom::contains<std::tuple<int, char, float, double, unsigned int, long>, float>::value, ""
	);
	static_assert(
		std::is_same <
			mpl_custom::at<std::tuple<int, char, float>, 1>,
			char
		>::value, ""
	);
	static_assert(
		mpl_custom::count<std::tuple<int, int>, int>::value == 2, ""
	);
	assert_same_type(
		std::tuple<int, float>{},
		mpl_custom::erase_all<std::tuple<int, char, char, char, float>, char>{}
	);
	assert_same_type(
		std::tuple<char, char, char, float>{},
		mpl_custom::erase_all<std::tuple<int, char, char, char, float>, int>{}
	);
	assert_same_type(
		std::tuple<int, char, float>{},
		mpl_custom::reverse<std::tuple<float, char, int>>{}
	);
	assert_same_type(
		mpl_custom::list<int, float>{},
		mpl_custom::no_duplicates<mpl_custom::list<int, float, int, float>>{}
	);
}