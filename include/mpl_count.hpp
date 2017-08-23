#pragma once

#include <type_traits>
#include "mpl_size.hpp"
#include "mpl_erase_all.hpp"

namespace mpl_custom {
	template<class container, class typeOccur>
	using count = typename std::integral_constant<std::size_t, size<container>::value - size<erase_all<container, typeOccur>>::value>::type;
}