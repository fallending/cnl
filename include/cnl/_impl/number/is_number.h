
//          Copyright John McFarlane 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file ../LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CNL_IMPL_NUMBER_IS_NUMBER_H)
#define CNL_IMPL_NUMBER_IS_NUMBER_H

#include "declaration.h"

#include <type_traits>

/// compositional numeric library
namespace cnl {
    namespace _impl {
        template<typename T>
        inline constexpr auto is_number = false;

        template<typename Rep, class Tag>
        inline constexpr auto is_number<_impl::number<Rep, Tag>> = true;
    }
}

#endif  // CNL_IMPL_NUMBER_IS_NUMBER_H
