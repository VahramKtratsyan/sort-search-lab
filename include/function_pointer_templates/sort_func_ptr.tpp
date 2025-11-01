#pragma once

#include <iterator>
#include <functional>
    
namespace ptr_to_sort_func
{   
    template<typename It>
    using PtrToCompSort = std::function<void(It, It, std::function<bool(const std::iter_value_t<It>&, const std::iter_value_t<It>&)>)>;

    template<typename It>
    using PtrToNonCompSort = std::function<void(It, It)>;
}   