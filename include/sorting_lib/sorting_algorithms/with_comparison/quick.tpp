#pragma once

#include "../../utilities/concept.tpp"
#include "../../utilities/partition.tpp"

namespace my_sort
{
    template <typename Comp, SortableIteratorWithComp<Comp> It>
    void quick(It first, It last, Comp comp)
    {
        if (last - first <= 1)
            return;

        auto pivot_index_in_sorted_arr = partition(first, last, comp);
        quick(first, pivot_index_in_sorted_arr, comp);
        quick(pivot_index_in_sorted_arr + 1, last, comp);
    } 
} 