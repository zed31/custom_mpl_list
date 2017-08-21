#include <tuple>
#include <vector>
#include "mpl_custom_list.hpp"
#include "proto_test.hh"

namespace mpl_test {
	void test_mpl_change() {
		assert_same_type(
			mpl_custom::list<int, char, float>{},
			mpl_custom::change<std::tuple<int, char, float>, mpl_custom::list>{}
		);
		assert_same_type(
			std::tuple<int, char, float>{},
			mpl_custom::change<mpl_custom::list<int, char, float>, std::tuple>{}
		);
		assert_same_type(
			mpl_custom::list<int, char, float>{},
			mpl_custom::change<std::tuple<int, char, float>, mpl_custom::list>{}
		);
		assert_same_type(
			std::vector<int>{},
			mpl_custom::change<mpl_custom::list<int>, std::vector>{}
		);
	}
}