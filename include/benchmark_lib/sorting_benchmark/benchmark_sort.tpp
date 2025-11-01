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
    void print_benchmark_header_for_sort()
    {
        std::cout << std::endl << "       === Sorting Benchmark ===" << std::endl;
        std::cout << std::left << std::setw(20) << "Algorithm";
        std::cout << std::right << std::setw(20) << "Time (µs)" << std::endl;
        std::cout << std::string(40, '-') << std::endl;
    }

    template <typename CompSortFuncAndFuncName, typename Container, typename Comp = std::less<typename Container::value_type>>
    void benchmarks_for_comp_sort(const CompSortFuncAndFuncName& sort, Container arr, bool print_header = true, Comp comp = Comp{})
    {
        if (print_header)
            print_benchmark_header_for_sort();

        auto cpy_of_original_arr = arr;
        for (std::size_t i = 0; i < sort.size(); ++i)
        {
            arr = cpy_of_original_arr;
            const auto start = std::chrono::steady_clock::now();
            sort[i].get_func()(arr.begin(), arr.end(), comp);
            const auto end = std::chrono::steady_clock::now();
            auto duration  = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            std::cout << std::left << std::setw(20) << sort[i].get_func_name();
            std::cout << std::right << std::setw(15) << duration << " µs\n";
        }
    }

    template <typename NonCompSortFuncAndFuncName, typename Container>
    void benchmarks_for_non_comp_sort(const NonCompSortFuncAndFuncName& sort, Container arr, bool print_header = true)
    {
        if (print_header)
            print_benchmark_header_for_sort();

        auto cpy_of_original_arr = arr;
        for (std::size_t i = 0; i < sort.size(); ++i)
        {
            arr = cpy_of_original_arr;
            const auto start = std::chrono::steady_clock::now();
            sort[i].get_func()(arr.begin(), arr.end());
            const auto end = std::chrono::steady_clock::now();
            auto duration  = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            std::cout << std::left << std::setw(20) << sort[i].get_func_name();
            std::cout << std::right << std::setw(15) << duration << " µs\n";
        }
    }
}