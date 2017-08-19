#pragma once

namespace mpl_custom {
	template<class container, int pos>
	struct at_impl;

	template<template<class...> class container, class T1, class... T>
	struct at_impl<container<T1, T...>, 0> {
		using type = T1;
	};

	template<template<class...> class container, class T1, class... T, int pos>
	struct at_impl<container<T1, T...>, pos> {
		using type = typename at_impl<container<T...>, pos - 1>::type;
	};

	template<class container, int pos>
	using at = typename at_impl<container, pos>::type;
}