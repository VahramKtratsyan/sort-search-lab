#pragma once

#include <algorithm>
#include <cmath>
#include "../../utilities/concept.tpp"
#include "../../utilities/counting_for_radix.tpp"

namespace my_sort
{
    template <SortableIteratorWithoutComp It>
    void radix(It first, It last)
    {
        using ValueType = std::iter_value_t<It>;

        if (first == last)
            return;

        if (std::any_of(first, last, [](const ValueType& el){return el < 0;}))
            throw std::invalid_argument("Radix sort supports only non-negative integers.");
        
        auto max = *std::max_element(first, last);
        auto count_of_digits_of_max = (max == 0) ? 1 : std::floor(std::log10(max)) + 1;
        auto current_digit_place = 1;
        for (auto i = 0; i < count_of_digits_of_max; ++i)
        {
            counting_for_radix(first, last, current_digit_place);
            current_digit_place *= 10;
        }
    }
}