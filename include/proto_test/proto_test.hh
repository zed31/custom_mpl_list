#include "mpl_custom_list.hpp"

namespace mpl_test {
	template<class T1, class T2>
	inline void assert_same_type(T1, T2) {
		T1{} = T2{};
	}

	void test_mpl_change();
	void test_mpl_push_back();
	void mpl_size();
	void mpl_push_front();
	void mpl_transform();
	void mpl_contains();
}