#include <type_traits>
#include <tuple>
#include <vector>
#include "proto_test.hh"

namespace mpl_test {
	template<std::size_t value>
	using checker_c = typename std::integral_constant<std::size_t, value>::type;

	void mpl_count() {
		assert_same_type(
			mpl_custom::count<std::tuple<int, float, int>, int>{},
			checker_c<2>{}
		);
		assert_same_type(
			mpl_custom::count<mpl_custom::list<int, float, int>, int>{},
			checker_c<2>{}
		);
		assert_same_type(
			mpl_custom::count<std::tuple<int>, int>{},
			checker_c<1>{}
		);
		assert_same_type(
			mpl_custom::count<std::tuple<std::vector<int>>, std::vector<int>>{},
			checker_c<1>{}
		);
	}
}