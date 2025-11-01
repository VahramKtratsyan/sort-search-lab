#pragma once

#include "../../utilities/concept.tpp"
#include "../../utilities/merge.tpp"

namespace my_sort 
{
    template <typename Comp, SortableIteratorWithComp<Comp> It>
    void merge_sort(It first, It last, Comp comp)
    {
        if (last - first <= 1)
            return;

        auto mid = first + (last - first) / 2;
        merge_sort(first, mid, comp);
        merge_sort(mid, last, comp);
        merge(first, mid, last, comp);
    }
} 