#pragma once

#include <string>
#include "../../../function_pointer_templates/search_func_ptr.tpp"
#include "benchmark_entry.tpp"

namespace benchmark_lab
{
    template<typename It>
    class BenchmarkEntryForSearch: 
        public BenchmarkEntry<It, ptr_to_search_func::PtrToSearch<It>>
    {
        using Base = BenchmarkEntry<It, ptr_to_search_func::PtrToSearch<It>>;
    public:    
        BenchmarkEntryForSearch(ptr_to_search_func::PtrToSearch<It> func, 
            const std::string& func_name): Base(func, func_name){}
        ~BenchmarkEntryForSearch() override = default;
    };
}