#pragma once

#include <iterator>
#include "utilities/concept.tpp"

namespace my_search
{
    template <LinearSearchIterator It>
    It linear(It first, It last, const std::iter_value_t<It>& value);

    template <SearchIterator It>
    It binary(It first, It last, const std::iter_value_t<It>& value);

    template <SearchIterator It>
    It jump(It first, It last, const std::iter_value_t<It>& value);

    template <SearchIterator It>
    It interpolation(It first, It last, const std::iter_value_t<It>& value);
}

#include "searching_algorithms/linear_search.tpp"
#include "searching_algorithms/binary_search.tpp"
#include "searching_algorithms/jump_search.tpp"
#include "searching_algorithms/interpolation.tpp"