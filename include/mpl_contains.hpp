#pragma once

namespace mpl_custom {
	template<class container, class compareType>
	struct contains_impl;

	template<template<class...> class container, class compareType>
	struct contains_impl<container<>, compareType> {
		static constexpr bool value = false;
	};

	template<template<class...> class container, class... T, class compareType>
	struct contains_impl<container<compareType, T...>, compareType> {
		static constexpr bool value = true;
		static constexpr bool rest = contains_impl<container<T...>, compareType>::value;
	};

	template<template<class...> class container, class T1, class... T, class compareType>
	struct contains_impl<container<T1, T...>, compareType> {
		static constexpr bool value = contains_impl<container<T...>, compareType>::value;
	};

	template<class container, class compareType>
	using contains = typename contains_impl<container, compareType>;
}