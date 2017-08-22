#pragma once

#include <type_traits>

namespace mpl_custom {
	template<class containerSrc>
	struct size_impl;

	template<template<class...> class containerSrc, class... T>
	struct size_impl<containerSrc<T...>> {
		using type = std::integral_constant<std::size_t, sizeof...(T)>;
	};

	template<class containerSrc>
	using size = typename size_impl<containerSrc>::type;
}