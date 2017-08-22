#include <tuple>
#include "proto_test.hh"
#include "mpl_custom_list.hpp"

namespace mpl_test {
	void mpl_push_front() {
		assert_same_type(
			mpl_custom::list<double, int, float>{},
			mpl_custom::push_front<mpl_custom::list<int, float>, double>{}
		);
		assert_same_type(
			mpl_custom::list<double, unsigned, char, int, float, int, float>{},
			mpl_custom::push_front<mpl_custom::list<int, float>, double, unsigned, char, int, float>{}
		);
		assert_same_type(
			std::tuple<double, char, char, int, float, int, float>{},
			mpl_custom::push_front<std::tuple<int, float>, double, char, char, int, float>{}
		);
	}
}