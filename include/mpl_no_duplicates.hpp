#pragma once

namespace mpl_custom {
	template<class container, class typeOccur>
	struct erase_all_impl;

	template<class container, class... T>
	struct push_front_impl;
}

#include "mpl_erase_all.hpp"
#include "mpl_push_front.hpp"

namespace mpl_custom {
	template<class container>
	struct no_duplicates_impl;

	template<template<class...> class container>
	struct no_duplicates_impl<container<>> {
		using type = container<>;
	};

	template<template<class...> class container, class T1, class... T>
	struct no_duplicates_impl<container<T1, T...>> {
		using containerCleaned = typename erase_all_impl<container<T...>, T1>::type;
		using rest = typename no_duplicates_impl<containerCleaned>::type;
		using type = typename push_front_impl<rest, T1>::type;
	};

	template<class container>
	using no_duplicates = typename no_duplicates_impl<container>::type;

}