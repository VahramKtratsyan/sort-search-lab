#pragma once

#include <functional>
#include "concept.tpp"
#include "../my_sort.hpp"

template <typename Comp = std::less<>, SortableIteratorWithComp<Comp> It>
It median(It first, It last, Comp comp = Comp{})
{
    my_sort::insertion(first, last, comp);
    auto res = first + (last - first) / 2;
    return res;
}