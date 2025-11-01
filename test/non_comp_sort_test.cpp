#include <vector>
#include <gtest/gtest.h>
#include <cstddef>
#include "../include/sorting_lib/my_sort.hpp"

template<typename T>
class TypedSortTest : public testing::TestWithParam<
std::function<void(typename std::vector<T>::iterator, typename std::vector<T>::iterator)>> 
{};

using UnsignedIntSortTest = TypedSortTest<std::size_t>;

INSTANTIATE_TEST_SUITE_P(
    IntSorts,
    UnsignedIntSortTest,
    testing::Values(
        [](auto first, auto last){ my_sort::counting(first, last); },
        [](auto first, auto last){ my_sort::radix(first, last); }
    )
);

TEST_P(UnsignedIntSortTest, SortEmptyArrAscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr;
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, std::vector<std::size_t>());
}

TEST_P(UnsignedIntSortTest, SortOneElementContainingArrWhichIS_0_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{0};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, std::vector<std::size_t>{0});
}

TEST_P(UnsignedIntSortTest, SortOneElementContainingArrWhichIS_1_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{1};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, std::vector<std::size_t>{1});
}

TEST_P(UnsignedIntSortTest, SortOneElementContainingArrWhichIS_2_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{2};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, std::vector<std::size_t>{2});
}

TEST_P(UnsignedIntSortTest, SortOneElementContainingArrWhichIS_10_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{10};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, std::vector<std::size_t>{10});
}

TEST_P(UnsignedIntSortTest, SortOneElementContainingArrWhichIS_21_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{21};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, std::vector<std::size_t>{21});
}

TEST_P(UnsignedIntSortTest, SortOneElementContainingArrWhichIS_1002_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{1002};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, std::vector<std::size_t>{1002});
}

TEST_P(UnsignedIntSortTest, SortTwoElementContainingArrWhichIS_0_0_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{0,0};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{0,0}));
}

TEST_P(UnsignedIntSortTest, SortTwoElementContainingArrWhichIS_0_1_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{0,1};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{0,1}));
}

TEST_P(UnsignedIntSortTest, SortTwoElementContainingArrWhichIS_1_0_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{1,0};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{0,1}));
}

TEST_P(UnsignedIntSortTest, SortTwoElementContainingArrWhichIS_1_1_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{1,1};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{1,1}));
}

TEST_P(UnsignedIntSortTest, SortTwoElementContainingArrWhichIS_105_1256_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{105,1256};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{105,1256}));
}

TEST_P(UnsignedIntSortTest, SortTreeElementContainingArrWhichIS_0_0_0_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{0,0,0};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{0,0,0}));
}

TEST_P(UnsignedIntSortTest, SortTreeElementContainingArrWhichIS_0_125_0_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{0,125,0};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{0,0,125}));
}

TEST_P(UnsignedIntSortTest, SortTreeElementContainingArrWhichIS_0_0_125_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{0,0,125};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{0,0,125}));
}

TEST_P(UnsignedIntSortTest, SortTreeElementContainingArrWhichIS_0_11_5286_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{0,11,5286};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{0,11,5286}));
}

TEST_P(UnsignedIntSortTest, SortTreeElementContainingArrWhichIS_11_0_5286_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{11,0,5286};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{0,11,5286}));
}

TEST_P(UnsignedIntSortTest, SortTreeElementContainingArrWhichIS_11_5286_0_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{11,5286,0};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{0,11,5286}));
}

TEST_P(UnsignedIntSortTest, SortTreeElementContainingArrWhichIS_5286_11_0_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{5286,11,0};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{0,11,5286}));
}

TEST_P(UnsignedIntSortTest, SortTreeElementContainingArrWhichIS_5286_0_0_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{5286,0,11};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{0,11,5286}));
}

TEST_P(UnsignedIntSortTest, SortTreeElementContainingArrWhichIS_0_5286_11_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{0,5286,11};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{0,11,5286}));
}

TEST_P(UnsignedIntSortTest, Sort_5_ElementContainingArrAscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{ 412, 9, 412, 9, 678};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{9, 9, 412, 412, 678}));
}

TEST_P(UnsignedIntSortTest, Sort_6_ElementContainingArrAscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{ 412, 9, 412, 9, 678, 412};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{9, 9, 412, 412, 412, 678}));
}

TEST_P(UnsignedIntSortTest, Sort_7_ElementContainingArrAscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{ 
        523, 87, 412, 9, 678, 234, 91
    };
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{
        9, 87, 91, 234, 412, 523, 678
    }));
}

TEST_P(UnsignedIntSortTest, Sort_10_ElementContainingArrAscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{ 
        523, 87, 412, 9, 678, 234, 91, 345, 102, 789
    };
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{
        9, 87, 91, 102, 234, 345, 412, 523, 678, 789
    }));
}

TEST_P(UnsignedIntSortTest, Sort_34_ElementContainingArrAscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{ 
            523, 87, 412, 9, 678, 234, 91, 345, 102, 789,
            56,  876, 321, 45, 678, 12, 999, 342, 65,
            123, 456, 789, 234, 87, 567, 890, 234, 345, 678,
            234, 56, 789, 234, 0
    };
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{
        0, 9, 12, 45, 56, 56, 65, 87, 87, 91, 102,
        123, 234, 234, 234, 234, 234, 321, 342,
        345, 345, 412, 456, 523, 567, 678, 678, 678, 789,
        789, 789, 876, 890, 999
    }));
}

TEST_P(UnsignedIntSortTest, Sort_65_ElementContainingArrAscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{ 
        523, 87, 412, 9, 678, 234, 91, 345, 102, 789,
        56, 234, 876, 321, 45, 678, 12, 999, 342, 65,
        123, 456, 789, 234, 87, 567, 890, 234, 345, 678,
        234, 56, 789, 234, 12, 345, 678, 90, 321, 456,
        234, 567, 89, 234, 678, 345, 123, 456, 789, 12,
        345, 678, 234, 56, 789, 123, 234, 567, 890, 234,
        345, 678, 123, 456, 789
    };
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{
        9, 12, 12, 12, 45, 56, 56, 56, 65, 87,
        87, 89, 90, 91, 102, 123, 123, 123, 123, 234,
        234, 234, 234, 234, 234, 234, 234, 234, 234, 234,
        321, 321, 342, 345, 345, 345, 345, 345, 345, 412,
        456, 456, 456, 456, 523, 567, 567, 567, 678, 678,
        678, 678, 678, 678, 678, 789, 789, 789, 789, 789,
        789, 876, 890, 890, 999
    }));
}

TEST_P(UnsignedIntSortTest, Sort_150_ElementContainingArrAscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{ 
        523, 87, 412, 9, 678, 234, 91, 345, 102, 789,
        56, 234, 876, 321, 45, 678, 12, 999, 342, 65,
        123, 456, 789, 234, 87, 567, 890, 234, 345, 678,
        234, 56, 789, 234, 12, 345, 678, 90, 321, 456,
        234, 567, 89, 234, 678, 345, 123, 456, 789, 12,
        345, 678, 234, 56, 789, 123, 234, 567, 890, 234,
        345, 678, 123, 456, 789, 234, 87, 567, 890, 234,
        345, 678, 234, 12, 345, 678, 90, 321, 456, 234,
        567, 89, 234, 678, 345, 123, 456, 789, 12, 345,
        678, 234, 56, 789, 123, 234, 567, 890, 234, 345,
        523, 87, 412, 9, 678, 234, 91, 345, 102, 789,
        56, 234, 876, 321, 45, 678, 12, 999, 342, 0,
        123, 456, 789, 234, 87, 567, 890, 234, 345, 678,
        234, 56, 789, 234, 12, 345, 678, 90, 321, 456,
        234, 567, 89, 234, 678, 345, 123, 456, 789, 12
    };
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{
        0, 9, 9, 12, 12, 12, 12, 12, 12, 12,
        12, 45, 45, 56, 56, 56, 56, 56, 56, 65,
        87, 87, 87, 87, 87, 89, 89, 89, 90, 90,
        90, 91, 91, 102, 102, 123, 123, 123, 123, 123,
        123, 123, 123, 234, 234, 234, 234, 234, 234, 234,
        234, 234, 234, 234, 234, 234, 234, 234, 234, 234,
        234, 234, 234, 234, 234, 234, 234, 234, 234, 234,
        321, 321, 321, 321, 321, 342, 342, 345, 345, 345,
        345, 345, 345, 345, 345, 345, 345, 345, 345, 345,
        345, 345, 412, 412, 456, 456, 456, 456, 456, 456,
        456, 456, 456, 523, 523, 567, 567, 567, 567, 567,
        567, 567, 567, 678, 678, 678, 678, 678, 678, 678,
        678, 678, 678, 678, 678, 678, 678, 678, 678, 789,
        789, 789, 789, 789, 789, 789, 789, 789, 789, 789,
        789, 876, 876, 890, 890, 890, 890, 890, 999, 999
    }));
}

TEST_P(UnsignedIntSortTest, Sort_100_ElementContainingArrAscendingOrder)
{
    auto sort = GetParam();
    std::vector<std::size_t> arr{ 
        523, 87, 412, 9, 678, 234, 91, 345, 102, 789,
        56, 234, 876, 321, 45, 678, 12, 999, 342, 65,
        123, 456, 789, 234, 87, 567, 890, 234, 345, 678,
        234, 56, 789, 234, 12, 345, 678, 90, 321, 456,
        234, 567, 89, 234, 678, 345, 123, 456, 789, 12,
        345, 678, 234, 56, 789, 123, 234, 567, 890, 234,
        345, 678, 123, 456, 789, 234, 87, 567, 890, 234,
        345, 678, 234, 12, 345, 678, 90, 321, 456, 234,
        567, 89, 234, 678, 345, 123, 456, 789, 12, 345,
        678, 234, 56, 789, 123, 234, 567, 890, 234, 345
};
    sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, (std::vector<std::size_t>{
        9, 12, 12, 12, 12, 12, 45, 56, 56, 56,
        56, 65, 87, 87, 87, 89, 89, 90, 90, 91,
        102, 123, 123, 123, 123, 123, 123, 234, 234, 234,
        234, 234, 234, 234, 234, 234, 234, 234, 234, 234,
        234, 234, 234, 234, 234, 234, 321, 321, 321, 342,
        345, 345, 345, 345, 345, 345, 345, 345, 345, 345,
        345, 412, 456, 456, 456, 456, 456, 456, 523, 567,
        567, 567, 567, 567, 567, 678, 678, 678, 678, 678,
        678, 678, 678, 678, 678, 678, 789, 789, 789, 789,
        789, 789, 789, 789, 876, 890, 890, 890, 890, 999
}));
}


using IntSortTest = TypedSortTest<int>;

INSTANTIATE_TEST_SUITE_P(
    IntSorts,
    IntSortTest,
    testing::Values(
        [](auto first, auto last){ my_sort::counting(first, last); }
    )
);

TEST_P(IntSortTest, SortOneElementContainingArrWhichIS_Minus1_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-1};
    EXPECT_THROW(sort(arr.begin(), arr.end()), std::invalid_argument);
}

TEST_P(IntSortTest, SortsevenElementContainingArrWhichContainsNegative_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{3,4,156,-5,7121,231,0};
    EXPECT_THROW(sort(arr.begin(), arr.end()), std::invalid_argument);
}

TEST_P(IntSortTest, Sort_100_ElementContainingArrWhichContainsNegativeAscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{ 
        523, 87, 412, 9, 678, 234, 91, 345, 102, 789,
        56, 234, 876, 321, 45, 678, 12, 999, 342, 65,
        123, 456, 789, 234, 87, 567, 890, 234, 345, 678,
        234, 56, 789, 234, 12, 345, 678, 90, 321, 456,
        234, 567, 89, 234, 678, 345, 123, 456, 789, 12,
        345, 678, 234, 56, 789, 123, 234, 567, 890, 234,
        345, 678, 123, 456, 789, 234, 87, 567, 890, 234,
        345, 678, 234, 12, 345, 678, 90, 321, 456, 234,
        567, 89, 234, 678, 345, 123, 456, 789, 12, 345,
        678, 234, 56, 789, 123, 234, 567, 890, 234, -9
};
    EXPECT_THROW(sort(arr.begin(), arr.end()), std::invalid_argument);
}