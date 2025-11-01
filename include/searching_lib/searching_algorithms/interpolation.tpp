#pragma once

#include <cmath>
#include "../utilities/concept.tpp"

namespace my_search
{
    template <SearchIterator It>
    It interpolation(It first, It last, const std::iter_value_t<It>& value)
    {
        if (last - first == 0)
            return last;

        auto first_ = first;
        auto last_ = last - 1;
        auto res = last;
        while (first_ <= last_)
        {
            auto denom = *last_ - *first_;
            if (denom == 0)
            {
                if (*first_ == value)
                    return first_; 
                else
                    break; 
            }

            auto size = last_ - first_;
            auto pos = first_ + std::floor((value - *first_) * size / denom);
            if (value == *pos)
                return pos;
            if (value > *pos)
                first_ = pos + 1;
            else
                last_ = pos;
        }
        return res;
    }
}