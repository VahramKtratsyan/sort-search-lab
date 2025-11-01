#pragma once

#include "../utilities/concept.tpp"

namespace my_search
{
    template <SearchIterator It>
    It binary(It first, It last, const std::iter_value_t<It>& value)
    {
        auto first_ = first;
        auto last_ = last;
        auto res = last;
        while (first_ != last_)
        {
            auto mid = first_ + (last_ - first_) / 2;
            if (*mid == value)
                res = last_ = mid;
            else if (value < *mid)
                last_ = mid;
            else
                first_ = mid + 1;
        }
        return res;
    }
}