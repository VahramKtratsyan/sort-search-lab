#pragma once

#include <algorithm>
#include "../../utilities/concept.tpp"

namespace my_sort 
{
    template <typename Comp, SortableIteratorWithComp<Comp> It>
    void bubble(It first, It last, Comp comp) 
    {
        if (first == last || first + 1 == last)
            return;

        bool is_sorted{};
        while (!is_sorted)
        {
            is_sorted = true;
            for (auto current = first, next = current + 1; next != last; ++current, ++next)
            {
                if (comp(*next, *current))
                {
                    is_sorted = false;
                    std::iter_swap(current, next);
                }
            }
        }
    }
}