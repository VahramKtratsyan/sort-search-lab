#pragma once

#include <functional>
#include <iterator>
#include <concepts>

template <typename It>
concept SortableIteratorWithoutComp = 
    std::forward_iterator<It> && std::integral<typename std::iterator_traits<It>::value_type>;

template <typename It, typename Comp = std::less<>>
concept SortableIteratorWithComp =
    std::random_access_iterator<It> && requires(Comp comp, It a, It b) {
        { comp(*a, *b) } -> std::convertible_to<bool>;
    };