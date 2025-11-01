#pragma once

#include <algorithm>
#include <cmath>
#include "linear_search.tpp"
#include "../utilities/concept.tpp"

namespace my_search
{
    template <SearchIterator It>
    It jump(It first, It last, const std::iter_value_t<It>& value)
    {
        auto jump_size = std::floor(std::sqrt(last - first));
        if (jump_size == 0)
            return last;

        auto begin_of_curr_range = first;
        auto end_of_curr_range = first;
        while ((end_of_curr_range < last - 1) && (value >= *end_of_curr_range))
        {
            if (value == *end_of_curr_range)
                break;
            begin_of_curr_range = end_of_curr_range;
            end_of_curr_range += std::min<int>(jump_size, last - end_of_curr_range - 1);
        }
        auto res = my_search::linear(begin_of_curr_range, end_of_curr_range + 1, value);
        return (res == end_of_curr_range + 1) ? last : res; 
    }
} 