#pragma once

#include "../../my_sort.hpp"

namespace my_sort
{
    namespace wrapper
    {
        auto bubble_func = [](auto first, auto last, auto comp) 
        {
            my_sort::bubble(first, last, comp); 
        };

        auto insertion_func = [](auto first, auto last, auto comp) 
        {
            my_sort::insertion(first, last, comp); 
        };

        auto selection_func = [](auto first, auto last, auto comp) 
        {
            my_sort::selection(first, last, comp); 
        };

        auto merge_func = [](auto first, auto last, auto comp) 
        {
            my_sort::merge_sort(first, last, comp); 
        };
            
        auto quick_func =  [](auto first, auto last, auto comp) 
        {
            my_sort::quick(first, last, comp); 
        };

        auto counting_func =  [](auto first, auto last) 
        {
            my_sort::counting(first, last); 
        };
            
        auto radix_func =  [](auto first, auto last) 
        {
            my_sort::radix(first, last); 
        };
    }
}