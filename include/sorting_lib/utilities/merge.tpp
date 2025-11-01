#pragma once

#include <utility>
#include <functional>
#include "concept.tpp"

template <typename Comp = std::less<>, SortableIteratorWithComp<Comp> It>
void merge(It first, It mid, It last, Comp comp = Comp{})
{
    using ValueType = std::iter_value_t<It>;

    std::vector<ValueType> buffer;
    buffer.reserve(last - first); 

    auto left = first;
    auto right = mid;

    while (left != mid && right != last)
    {
        if (comp(*left, *right))
            buffer.push_back(*(left++));

        else
            buffer.push_back(*(right++));
    }

    while (left != mid)
        buffer.push_back(*(left++));

    while (right != last)
        buffer.push_back(*(right++));
    
    std::move(buffer.begin(), buffer.end(), first);
}