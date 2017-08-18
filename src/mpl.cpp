#include <type_traits>
#include <tuple>
#include "../include/mpl_change.hpp"
#include "../include/mpl_list.hpp"
#include "../include/mpl_size.hpp"
#include "../include/mpl_push_front.hpp"
#include "../include/mpl_push_back.hpp"

int main() {
	static_assert(
		mpl_custom::size<std::tuple<int, float, char, void>>::value == 4, ""
	);

	/* New way of testing things Because I worth it !!!! */
	mpl_custom::list<int, float, double>{} = mpl_custom::push_back<mpl_custom::list<int, float>, double>{};
	mpl_custom::list<int, char, float>{} = mpl_custom::change<std::tuple<int, char, float>, mpl_custom::list>{};
	std::tuple<char, int, float>{} = mpl_custom::push_front<std::tuple<int, float>, char>{};
}