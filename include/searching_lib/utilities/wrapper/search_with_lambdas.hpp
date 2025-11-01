#pragma once

#include "../../my_search.hpp"

namespace my_search
{
    namespace wrapper
    {
        auto linear_func = [](auto first, auto last, auto value) 
        {
            my_search::linear(first, last, value); 
        };
      
        auto binary_func = [](auto first, auto last, auto value) 
        {
            my_search::binary(first, last, value); 
        };

        auto jump_func = [](auto first, auto last, auto value) 
        {
            my_search::jump(first, last, value); 
        };
        
        auto interpolation_func = [](auto first, auto last, auto value) 
        {
            my_search::interpolation(first, last, value); 
        };
    }
}
