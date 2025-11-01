#pragma once

#include <functional>
#include <algorithm>
#include "median.tpp"
#include "../my_sort.hpp"

template <typename Comp = std::less<>, SortableIteratorWithComp<Comp> It>
It median_of_medians(It first, It last, Comp comp = Comp{})
{
    if (last - first <= 5)
        return median(first, last, comp);
    
    auto group_start = first;
    auto medians_current_index = first;

    while (group_start != last)
    {
        auto group_end = group_start + std::min<std::ptrdiff_t>(5, last - group_start);
        auto current_median = median(group_start, group_end, comp);
        std::iter_swap(medians_current_index++, current_median);
        group_start += (group_end - group_start);
    }
    return median_of_medians(first, medians_current_index, comp);
}    