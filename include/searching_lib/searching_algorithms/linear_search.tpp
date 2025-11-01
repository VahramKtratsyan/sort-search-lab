#pragma once

#include "../utilities/concept.tpp"

namespace my_search 
{
    template <LinearSearchIterator It>
    It linear(It first, It last, const std::iter_value_t<It>& value)
    {
        for (auto i = first; i != last; ++i)
            if (*i == value)
                return i;  
        return last;  
    }
}