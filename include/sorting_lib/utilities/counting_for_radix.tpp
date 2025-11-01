#pragma once

#include <utility>
#include "concept.tpp"

template <SortableIteratorWithoutComp It>
void counting_for_radix(It first, It last, int place)
{
    using ValueType = std::iter_value_t<It>;

    const std::size_t size_of_indexes = 10;
    std::vector<std::size_t> indexes(size_of_indexes);
        
    for (auto i = first; i != last; ++i)
        ++indexes[(*(i) / place) % 10];

    for (std::size_t i = 1; i < size_of_indexes; ++i)
        indexes[i] += indexes[i - 1];
        
    std::vector<ValueType> result(last - first);
    for (auto i = last - 1; i != first - 1; --i)
        result[--indexes[(*i / place) % 10]] = *i;
    std::move(result.begin(), result.end(), first);
}