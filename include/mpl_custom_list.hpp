#pragma once

#include "mpl_apply.hpp"
#include "mpl_at.hpp"
#include "mpl_change.hpp"
#include "mpl_contains.hpp"
#include "mpl_count.hpp"
#include "mpl_list.hpp"
#include "mpl_meta_function.hpp"
#include "mpl_push_back.hpp"
#include "mpl_push_front.hpp"
#include "mpl_size.hpp"
#include "mpl_erase_all.hpp"

namespace mpl_custom {
	template<class container, unsigned pos>
	using at = typename at_impl<container, pos>::type;

	template<class container, class compareType>
	using contains = typename contains_impl<container, compareType>;

	template<class container, template<class...> class metaFunction>
	using apply = typename apply_impl<container, metaFunction>::type;

	template<class containerSrc, template<class...> class containerDest>
	using change = typename change_impl<containerSrc, containerDest>::type;

	template<class container, class typeOccur>
	using count = typename count_impl<container, typeOccur>;

	template<class container, class insert>
	using push_back = typename push_back_impl<container, insert>::type;

	template<class container, class... T>
	using push_front = typename push_front_impl<container, T...>::type;

	template<class containerSrc>
	using size = typename size_impl<containerSrc>;

	template<class container, class typeErase>
	using erase_all = typename erase_all_impl<container, typeErase>::type;
}