#pragma once

#include <functional>
#include "utilities/concept.tpp"

namespace my_sort 
{
    template <typename Comp = std::less<>, SortableIteratorWithComp<Comp> It>
    void bubble(It first, It last, Comp comp = Comp{});

    template <typename Comp = std::less<>, SortableIteratorWithComp<Comp> It>
    void selection(It first, It last, Comp comp = Comp{});

    template <typename Comp = std::less<>, SortableIteratorWithComp<Comp> It>
    void insertion(It first, It last, Comp comp = Comp{});

    template <typename Comp = std::less<>, SortableIteratorWithComp<Comp> It>
    void merge_sort(It first, It last, Comp comp = Comp{});

    template <typename Comp = std::less<>, SortableIteratorWithComp<Comp> It>
    void quick(It first, It last, Comp comp = Comp{});

    template <SortableIteratorWithoutComp It>
    void counting(It first, It last);

    template <SortableIteratorWithoutComp It>
    void radix(It first, It last);
}

#include "sorting_algorithms/with_comparison/bubble.tpp"
#include "sorting_algorithms/with_comparison/selection.tpp"
#include "sorting_algorithms/with_comparison/insertion.tpp"
#include "sorting_algorithms/with_comparison/merge.tpp"
#include "sorting_algorithms/with_comparison/quick.tpp"
#include "sorting_algorithms/without_comparison/counting.tpp"
#include "sorting_algorithms/without_comparison/radix.tpp"