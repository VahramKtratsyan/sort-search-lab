#pragma once

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <utility>
#include "../../utilities/concept.tpp"

namespace my_sort
{
    template <SortableIteratorWithoutComp It>
    void counting(It first, It last)
    {
        using ValueType = std::iter_value_t<It>;
        
        if (first == last)
            return;
        
        if (std::any_of(first, last, [](const ValueType& el){return el < 0;}))
            throw std::invalid_argument("Counting sort supports only non-negative integers.");

        auto min = *std::min_element(first, last);
        auto max = *std::max_element(first, last);
        const std::size_t size_of_indexes = max - min + 1;
        std::vector<std::size_t> indexes(size_of_indexes);
        
        for (auto i = first; i != last; ++i)
            ++indexes[*i - min];

        for (std::size_t i = 1; i < size_of_indexes; ++i)
            indexes[i] += indexes[i - 1];
        
        std::vector<ValueType> result(last - first);
        for (auto i = first; i != last; ++i)
            result[--indexes[*i - min]] = *i;

        std::move(result.begin(), result.end(), first);
    }
}