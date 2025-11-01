#pragma once

#include <algorithm>
#include "../../utilities/concept.tpp"

namespace my_sort
{
    template<typename Comp, SortableIteratorWithComp<Comp> It>
    void selection(It first, It last, Comp comp)
    {
        for (auto begin = first; begin != last; ++begin)
        {
            auto selected_element = begin;
            for (auto current = begin + 1; current != last; ++current)
                selected_element =  comp(*current, *selected_element) ? current : selected_element;
            std::iter_swap(begin, selected_element);
        }
    }
} 