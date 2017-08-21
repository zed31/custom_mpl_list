#pragma once

namespace mpl_custom{
	template<typename container, class... T>
	struct push_back_impl;
}

#include "mpl_push_back.hpp"

namespace mpl_custom {
	template<typename container>
	struct reverse_impl;

	template<template<class...> class container>
	struct reverse_impl<container<>> {
		using type = container<>;
	};

	template<template<class...> class container, class T1, class... T>
	struct reverse_impl<container<T1, T...>> {
		using type = typename push_back_impl<container<T...>, T1>::type;
	};

	template<class container>
	using reverse = typename reverse_impl<container>::type;
}