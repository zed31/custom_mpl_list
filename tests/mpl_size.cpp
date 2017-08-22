#include <vector>
#include <tuple>
#include <map>
#include <type_traits>
#include <memory>
#include "proto_test.hh"
#include "mpl_custom_list.hpp"

template<std::size_t value>
using checker_c = typename std::integral_constant<std::size_t, value>;

namespace mpl_test {
	void mpl_size() {
		assert_same_type(
			mpl_custom::size<std::tuple<int, float, char, double*>>{}, checker_c<4>{}
		);
		assert_same_type(
			mpl_custom::size<std::vector<int>>{}, checker_c<2>{}
		);
		assert_same_type(
			mpl_custom::size<mpl_custom::list<int, checker_c<3>>>{}, checker_c<2>{}
		);
		assert_same_type(
			mpl_custom::size<std::unique_ptr<int>>{}, checker_c<2>{}
		);
		assert_same_type(
			mpl_custom::size<std::map<int, char>>{}, checker_c<4>{}
		);
	}
}
