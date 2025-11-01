#pragma once

#include <string>

namespace benchmark_lab
{
template<typename It, typename FuncType>
    class BenchmarkEntry
    {
    protected:
        FuncType func;
        std::string func_name;

    public:
        BenchmarkEntry(FuncType func, const std::string& func_name)
            : func(func), func_name(func_name) {}
        const std::string& get_func_name() const { return this -> func_name; }
        FuncType get_func() const { return this -> func; }
        virtual ~BenchmarkEntry() = 0;   
    };

    template<typename It, typename FuncType>
    BenchmarkEntry<It, FuncType>::~BenchmarkEntry() = default;
}