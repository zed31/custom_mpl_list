#include <tuple>
#include "proto_test.hh"
#include "mpl_custom_list.hpp"

namespace mpl_test {
	void test_mpl_push_back() {
		assert_same_type(
			mpl_custom::list<int, float, double>{},
			mpl_custom::push_back<mpl_custom::list<int, float>, double>{}
		);
		assert_same_type(
			mpl_custom::list<int, float, double, char, char, int, float>{},
			mpl_custom::push_back<mpl_custom::list<int, float>, double, char, char, int, float>{}
		);
		assert_same_type(
			std::tuple<int, float, double, char, char, int, float>{},
			mpl_custom::push_back<std::tuple<int, float>, double, char, char, int, float>{}
		);
	}
}