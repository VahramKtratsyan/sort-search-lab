#pragma once

#include "../../utilities/concept.tpp"

namespace my_sort
{
    template <typename Comp, SortableIteratorWithComp<Comp> It>
    void insertion(It first, It last, Comp comp)
    {
        if (first == last)
            return;
        
        for (auto current = first + 1; current != last; ++current)
        {
            auto key = *current;
            auto previous = current - 1;
            while(previous >= first)
            {
                if (comp(key, *previous))
                    *(previous + 1) = *previous;
            
                else
                    break;
                    
                --previous;        
            }
            *(previous + 1) = key;
        }
    }
}