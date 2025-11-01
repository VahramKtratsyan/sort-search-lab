#pragma once

#include <algorithm>
#include "concept.tpp"
#include "median_of_meedians.tpp"

template <typename Comp = std::less<>, SortableIteratorWithComp<Comp> It>
It partition(It first, It last, Comp comp = Comp{})
{
    It pivot_index = median_of_medians(first, last, comp);
    std::iter_swap(pivot_index, last - 1);

    auto pivot_index_in_sorted_arr = first - 1;
    auto current = first;
    while (current != last)
    {
        if (comp(*current, *(last - 1)))
            std::iter_swap(++pivot_index_in_sorted_arr, current);
        ++current;
    }
            
    std::iter_swap(++pivot_index_in_sorted_arr, (last - 1));
    return pivot_index_in_sorted_arr;
}