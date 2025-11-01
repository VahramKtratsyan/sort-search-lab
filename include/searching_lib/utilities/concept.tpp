#pragma once

#include <concepts>
#include <iterator>

template <typename It>
concept SearchIterator = std::random_access_iterator<It>; 

template <typename It>
concept LinearSearchIterator = std::input_iterator<It>;