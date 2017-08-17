#include <iostream>
#include <type_traits>
#include <tuple>
#include "../include/mpl_change.hpp"
#include "../include/mpl_list.hpp"

int main() {
    std::cout << "Hello world" << std::endl;
	static_assert( 
		std::is_same<mpl_custom::list<int, char, float>, mpl_custom::change<std::tuple<int, char, float>, mpl_custom::list>>::value, 
		"Error : expected mpl_custom::list<int, char, float>"
	);
}