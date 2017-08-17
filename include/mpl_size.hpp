#pragma once

#include <type_traits>

namespace mpl_custom {
	template<class containerSrc>
	struct size_impl;

	template<template<class...> class containerSrc, class... T>
	struct size_impl<containerSrc<T...>> {
		static constexpr std::size_t value = sizeof...(T);
	};

	template<class containerSrc>
	using size = typename size_impl<containerSrc>;
}