#include "proto_test.hh"

int main() {
	/*
	static_assert(
		std::is_same <
			mpl_custom::at<std::tuple<int, char, float>, 1>,
			char
		>::value, ""
	);
	static_assert(
		mpl_custom::count<std::tuple<int, int>, int>::value == 2, ""
	);
	assert_same_type(
		std::tuple<int, float>{},
		mpl_custom::erase_all<std::tuple<int, char, char, char, float>, char>{}
	);
	assert_same_type(
		std::tuple<char, char, char, float>{},
		mpl_custom::erase_all<std::tuple<int, char, char, char, float>, int>{}
	);
	assert_same_type(
		std::tuple<int, char, float>{},
		mpl_custom::reverse<std::tuple<float, char, int>>{}
	);
	assert_same_type(
		mpl_custom::list<int, float>{},
		mpl_custom::no_duplicates<mpl_custom::list<int, float, int, float>>{}
	); */
	mpl_test::test_mpl_change();
	mpl_test::test_mpl_push_back();
	mpl_test::mpl_size();
	mpl_test::mpl_push_front();
	mpl_test::mpl_transform();
	mpl_test::mpl_contains();
}