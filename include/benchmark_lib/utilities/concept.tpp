#pragma once

#include <concepts>
#include <string>
#include <vector>
#include <functional>
#include "../../function_pointer_templates/search_func_ptr.tpp"
#include "../../function_pointer_templates/sort_func_ptr.tpp"

template <typename C, typename It>
concept CompSortFuncAndFuncName = requires(C c) 
{
    { c.get_func() } -> std::convertible_to<ptr_to_sort_func::PtrToCompSort<It>>;
    { c.get_func_name() } -> std::convertible_to<std::string>;
};

template <typename C, typename It>
concept NonCompSortFuncAndFuncName = requires(C c) 
{
    { c.get_func() } -> std::convertible_to<ptr_to_sort_func::PtrToNonCompSort<It>>;
    { c.get_func_name() } -> std::convertible_to<std::string>;
};

template <typename C, typename It>
concept SearchFuncAndFuncName = requires(C c) 
{
    { c.get_func() } -> std::convertible_to<ptr_to_search_func::PtrToSearch<It>>;
    { c.get_func_name() } -> std::convertible_to<std::string>;
};