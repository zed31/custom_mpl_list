#pragma once

namespace custom {
	template<template<class...> typename container>
	struct mp_rename_impl;

	template<template<class...> typename containerSrc, class... T, template<class...> typename containerDest>
	struct mp_rename_impl<containerSrc<T...>, containerDest> {
		using type = containerDest<T...>;
	};

	template<template<class...> class containerSrc, typename containerDest>
	using mp_rename = typename mp_rename_impl<containerSrc, containerDest>::type;
}