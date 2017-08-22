#include <tuple> 
#include "proto_test.hh"

namespace mpl_test {
	void mpl_at_c() {
		static_assert(
			std::is_same<
				mpl_custom::at_c<std::tuple<int, char, float>, 1>,
				char
			>::value, ""
		);
		static_assert(
			std::is_same<
				mpl_custom::at_c<std::tuple<int, char, float>, 2>,
				float
			>::value, ""
		);
		static_assert(
			std::is_same<
				mpl_custom::at_c<mpl_custom::list<int, char, float>, 1>,
				char
			>::value, ""
		);
		static_assert(
			std::is_same<
				mpl_custom::at_c<mpl_custom::list<int, char, float>, 0>,
				int
			>::value, ""
		);
	}
}