#pragma once

#include <string>
#include "../../../function_pointer_templates/sort_func_ptr.tpp"
#include "benchmark_entry.tpp"

namespace benchmark_lab
{
    template<typename It>
    class BenchmarkEntryForCompSort: 
        public BenchmarkEntry<It, ptr_to_sort_func::PtrToCompSort<It>>
    {
        using Base = BenchmarkEntry<It, ptr_to_sort_func::PtrToCompSort<It>>;
    public:
        BenchmarkEntryForCompSort(ptr_to_sort_func::PtrToCompSort<It> func, 
            const std::string& func_name): Base(func, func_name){}
        ~BenchmarkEntryForCompSort() override = default;
    };

    template<typename It>
    class BenchmarkEntryForNonCompSort: 
        public BenchmarkEntry<It, ptr_to_sort_func::PtrToNonCompSort<It>>
    {
        using Base = BenchmarkEntry<It, ptr_to_sort_func::PtrToNonCompSort<It>>;
    public:    
        BenchmarkEntryForNonCompSort(ptr_to_sort_func::PtrToNonCompSort<It> func, 
            const std::string& func_name): Base(func, func_name){}
        ~BenchmarkEntryForNonCompSort() override = default;
    };
}