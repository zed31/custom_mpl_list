#pragma once
#include "mpl_push_front.hpp"

namespace mpl_custom {
	template<class container, class typeErase>
	struct erase_all_impl;

	template<template<class...> class container, class typeErase>
	struct erase_all_impl<container<>, typeErase> {
		using type = container<>;
	};

	template<template<class...> class container, class... T, class typeErase>
	struct erase_all_impl<container<typeErase, T...>, typeErase> {
		using type = typename erase_all_impl<container<T...>, typeErase>::type;
	};

	template<template<class...> class container, class T1, class... T, class typeErase>
	struct erase_all_impl<container<T1, T...>, typeErase> {
		using rest = typename erase_all_impl<container<T...>, typeErase>::type;
		using type = typename push_front_impl<rest, T1>::type;
	};

	template<class container, class typeErase>
	using erase_all = typename erase_all_impl<container, typeErase>::type;
}