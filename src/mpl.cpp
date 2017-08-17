#include <type_traits>
#include <tuple>
#include "../include/mpl_change.hpp"
#include "../include/mpl_list.hpp"
#include "../include/mpl_size.hpp"

int main() {
	static_assert( 
		std::is_same<
			mpl_custom::list<int, char, float>, 
			mpl_custom::change<
				std::tuple<int, char, float>, 
				mpl_custom::list
			>
		>::value, 
		"Error : expected mpl_custom::list<int, char, float>"
	);
	static_assert(
		mpl_custom::size<std::tuple<int, float, char, void>>::value == 4, ""
	);
}