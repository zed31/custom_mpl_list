#pragma once

namespace mpl_custom {
	template<class T>
	using add_pointer = T*;

	template<class T>
	using add_const_pointer = const T*;
}