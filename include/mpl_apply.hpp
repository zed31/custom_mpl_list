#pragma once

namespace mpl_custom {
	template<class container, template<class...> class metaFunction>
	struct apply_impl;

	template<template<class...> class container, class... T, template<class...> class metaFunction>
	struct apply_impl<container<T...>, metaFunction> {
		using type = container<metaFunction<T>...>;
	};

	template<class container, template<class...> class metaFunction>
	using apply = typename apply_impl<container, metaFunction>::type;
}