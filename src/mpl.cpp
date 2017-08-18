#include <type_traits>
#include <tuple>
#include <iostream>
#include "mpl_change.hpp"
#include "mpl_list.hpp"
#include "mpl_size.hpp"
#include "mpl_push_front.hpp"
#include "mpl_push_back.hpp"
#include "mpl_meta_function.hpp"
#include "mpl_apply.hpp"
#include "mpl_meta_function.hpp"
#include "mpl_contains.hpp"

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
		std::tuple<char, int, float>{}, 
		mpl_custom::push_front<std::tuple<int, float>, char>{}
	);
	assert_same_type(
		mpl_custom::apply<std::tuple<char, int, float>, mpl_custom::add_pointer>{},
		std::tuple<char *, int *, float *>{}
	);
	static_assert(
		mpl_custom::contains<std::tuple<char, int, float>, float>::value, ""
	);
	static_assert(
		mpl_custom::contains<std::tuple<int, char, float, double, unsigned int, long>, float>:: value, ""
	);
}