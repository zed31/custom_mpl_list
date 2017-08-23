#include <tuple>
#include "proto_test.hh"

namespace mpl_test {
	void mpl_erase_all() {
		assert_same_type(
			mpl_custom::erase_all<std::tuple<int, int, int, float>, int>{},
			std::tuple<float>{}
		);
		assert_same_type(
			mpl_custom::erase_all<std::tuple<int, int, int>, int>{},
			std::tuple<>{}
		);
		assert_same_type(
			mpl_custom::erase_all<mpl_custom::list<int, int, int>, int>{},
			mpl_custom::list<>{}
		);
		assert_same_type(
			mpl_custom::erase_all<mpl_custom::list<int, int, int, float>, int>{},
			mpl_custom::list<float>{}
		);
		assert_same_type(
			mpl_custom::erase_all<mpl_custom::list<float, int, int, float>, int>{},
			mpl_custom::list<float, float>{}
		);
	}
}