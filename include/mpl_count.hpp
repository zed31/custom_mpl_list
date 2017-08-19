#pragma once

namespace mpl_custom {
	template<class container, class typeOccur>
	struct count_impl;

	template<template<class...> class container, class typeOccur>
	struct count_impl<container<>, typeOccur> {
		static constexpr std::size_t value = 0;
	};

	template<template<class...> class container, class... T, class typeOccur>
	struct count_impl<container<typeOccur, T...>, typeOccur> {
		static constexpr std::size_t value = 1 + count_impl<container<T...>, typeOccur>::value;
	};

	template<template<class...> class container, class T1, class... T, class typeOccur>
	struct count_impl<container<T1, T...>, typeOccur> {
		static constexpr std::size_t value = 0 + count_impl<container<T...>, typeOccur>::value;
	};
}