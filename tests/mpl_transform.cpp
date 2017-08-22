#include <tuple>
#include "proto_test.hh"
#include "mpl_custom_list.hpp"

namespace mpl_test {
	void mpl_transform() {
		assert_same_type(
			mpl_custom::transform<std::tuple<char, int, float>, mpl_custom::add_pointer>{},
			std::tuple<char *, int *, float *>{}
		);
	}
}