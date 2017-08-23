#include <tuple>
#include "proto_test.hh"

namespace mpl_test {
	void mpl_reverse() {
		assert_same_type(
			mpl_custom::reverse<mpl_custom::list<int, float, char>>{},
			mpl_custom::list<char, float, int>{}
		);
		assert_same_type(
			mpl_custom::reverse<mpl_custom::list<void *, double, float, float, char>>{},
			mpl_custom::list<char, float, float, double, void*>{}
		);
	}
}