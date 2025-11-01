#pragma once

#include <chrono>
#include <iostream>
#include <vector>
#include <functional>
#include <iomanip>
#include <ios>
#include "../utilities/concept.tpp"

namespace benchmark_lab
{
    void print_benchmark_header_for_search()
    {
        std::cout << std::endl << "       === Searching Benchmark ===" << std::endl;
        std::cout << std::left << std::setw(20) << "Algorithm";
        std::cout << std::right << std::setw(20) << "Time (µs)" << std::endl;
        std::cout << std::string(40, '-') << std::endl;
    }

    template <typename SearchFuncAndFuncName, typename Container>
    void benchmarks_for_search(const SearchFuncAndFuncName& search, Container& arr, const typename Container::value_type& value, const bool print_header = true)
    {
        if (print_header)
            print_benchmark_header_for_search();

        for (std::size_t i = 0; i < search.size(); ++i)
        {
            const auto start = std::chrono::steady_clock::now();
            search[i].get_func()(arr.begin(), arr.end(), value);
            const auto end = std::chrono::steady_clock::now();
            auto duration  = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            std::cout << std::left << std::setw(20) << search[i].get_func_name();
            std::cout << std::right << std::setw(15) << duration << " ns\n";
        }
    }
}