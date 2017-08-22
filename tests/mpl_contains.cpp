#include <type_traits>
#include <tuple>
#include <vector>
#include "proto_test.hh"

namespace mpl_test {
	template<bool value>
	using checker_c = std::integral_constant<bool, value>;

	void mpl_contains() {
		assert_same_type(
			mpl_custom::contains<std::tuple<int, float>, int>{}, checker_c<true>{}
		);
		assert_same_type(
			mpl_custom::contains<mpl_custom::list<int>, float>{}, checker_c<false>{}
		);
		assert_same_type(
			mpl_custom::contains<std::vector<int>, std::allocator<int>>{}, checker_c<true>{}
		);
	}
}