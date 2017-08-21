namespace mpl_test {
	template<class T1, class T2>
	inline void assert_same_type(T1, T2) {
		T1{} = T2{};
	}

	void test_mpl_change();
}