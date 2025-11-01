#pragma once

#include <iterator>
#include <functional>

namespace ptr_to_search_func
{   
    template<typename It>
    using PtrToSearch = std::function<void(It, It, const std::iter_value_t<It>&)>;
} 