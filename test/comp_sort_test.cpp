#include <vector>
#include <gtest/gtest.h>
#include <chrono>
#include "../include/sorting_lib/my_sort.hpp"
#include <iomanip>

template<typename T>
class TypedSortTest : public testing::TestWithParam<
std::function<void(typename std::vector<T>::iterator, typename std::vector<T>::iterator, std::function<bool(const T&, const T&)>)>> 
{};

using IntSortTest = TypedSortTest<int>;

INSTANTIATE_TEST_SUITE_P(
    IntSorts,
    IntSortTest,
    testing::Values(
        [](auto first, auto last, auto comp = std::less<>{}){ my_sort::bubble(first, last, comp); },
        [](auto first, auto last, auto comp = std::less<>{}){ my_sort::insertion(first, last, comp); },
        [](auto first, auto last, auto comp = std::less<>{}){ my_sort::selection(first, last, comp); },
        [](auto first, auto last, auto comp = std::less<>{}){ my_sort::merge_sort(first, last, comp); },
        [](auto first, auto last, auto comp = std::less<>{}){ my_sort::quick(first, last, comp); }
    )
);

TEST_P(IntSortTest, SortEmptyArrAscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr;
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, std::vector<int>());
}

TEST_P(IntSortTest, SortOneElementContainingArrWhichIS_0_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{0};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, std::vector<int>{0});
}

TEST_P(IntSortTest, SortOneElementContainingArrWhichIS_1_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{1};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, std::vector<int>{1});
}

TEST_P(IntSortTest, SortOneElementContainingArrWhichIS_Minus1_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-1};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, std::vector<int>{-1});
}

TEST_P(IntSortTest, SortOneElementContainingArrWhichIS_67_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{67};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, std::vector<int>{67});
}

TEST_P(IntSortTest, SortOneElementContainingArrWhichIS_Minus67_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-67};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, std::vector<int>{-67});
}

TEST_P(IntSortTest, SortTwoElementContainingArr_0_0_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{0,0};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{0,0}));
}

TEST_P(IntSortTest, SortTwoSortedElementContainingArr_1_5_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{1,5};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{1,5}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_5_1_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{5,1};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{1,5}));
}

TEST_P(IntSortTest, SortTwoSortedElementContainingArr_Minus5_Minus1_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-5,-1};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-5,-1}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_Minus1_Minus5_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-1,-5};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-5,-1}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_5_Minus1_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{5,-1};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-1,5}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_Minus1_5_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-1,5};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-1,5}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_42_9_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{42,9};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{9,42}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_Minus9_Minus42_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-9,-42};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-42,-9}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_6578_0_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{6578,0};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{0,6578}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_Minus6578_0_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-6578,0};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-6578,0}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_0_Minus6578_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{0,-6578};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-6578,0}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_0_6578_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{0,6578};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{0,6578}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_1_1_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{1,1};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{1,1}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_978512_978512_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{978512,978512};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{978512,978512}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_Minus978512_Minus978512_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-978512,-978512};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-978512,-978512}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_0_0_0_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{0,0,0};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{0,0,0}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_4_42_986_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{4,42,986};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{4,42,986}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_42_4_986_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{42,4,986};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{4,42,986}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_42_986_4_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{42,986,4};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{4,42,986}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_986_42_4_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{986,42,4};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{4,42,986}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_986_4_42_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{986,4,42};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{4,42,986}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_4_986_42_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{4, 986, 42};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{4,42,986}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus986_4_42_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-986,4,42};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-986,4,42}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_4_Minus986_42_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{4,-986,42};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-986,4,42}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_4_42_Minus986_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{4,42,-986};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-986,4,42}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_42_4_Minus986_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{42,4,-986};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-986,4,42}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus986_Minus4_42_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-986,-4,42};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-986,-4,42}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus4_Minus986_42_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-4,-986,42};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-986,-4,42}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus986_4_Minus42_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-986,4,-42};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-986,-42,4}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus42_4_Minus986_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-42,4,-986};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-986,-42,4}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus986_Minus4_Minus42_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-986,-4,-42};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-986,-42,-4}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus4_Minus986_Minus42_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-4,-986,-42};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-986,-42,-4}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_0_Minus4_Minus42_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{0,-4,-42};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-42,-4,0}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus4_0_Minus42_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-4,0,-42};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-42,-4,0}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus4_Minus42_0_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-4,-42,0};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-42,-4,0}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus42_Minus4_0_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-42,-4,0};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-42,-4,0}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_15_15_15_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{15, 15, 15};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{15,15,15}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus15_Minus15_Minus15_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-15, -15, -15};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-15,-15,-15}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus15_15_Minus15_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-15, 15, -15};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-15,-15,15}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_15_Minus15_Minus15_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{15,-15,-15};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-15,-15,15}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus15_Minus15_15_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-15,-15, 15};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<int>{-15,-15,15}));
}

TEST_P(IntSortTest, SortEmptyArrDescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr;
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, std::vector<int>());
}

TEST_P(IntSortTest, Sort_45_ElementContainingArrAscendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{ 
            523, 87, 412, 9, 678, 234, 91, 345, 102, 789,
            56,  876, 321, 45, -6, -5, -4, -3, -2, -1, 678, 12, 999, 342, 65,
            123, 456, 789, 234, -100, -50, -10, -9, -8, -7, 
             87, 567, 890, 234, 345, 678,
            234, 56, 789, 234, 0
    };
    sort(arr.begin(), arr.end(), std::less<int>{});
    EXPECT_EQ(arr, (std::vector<int>{
        -100, -50, -10, -9, -8, -7, -6, -5, -4, -3,
        -2, -1, 0, 9, 12, 45, 56, 56, 65, 87,
        87, 91, 102, 123, 234, 234, 234, 234, 234, 321,
        342, 345, 345, 412, 456, 523, 567, 678, 678, 678,
        789, 789, 789, 876, 890, 999
    }));
}

TEST_P(IntSortTest, SortOneElementContainingArrWhichIS_0_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{0};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, std::vector<int>{0});
}

TEST_P(IntSortTest, SortOneElementContainingArrWhichIS_1_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{1};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, std::vector<int>{1});
}

TEST_P(IntSortTest, SortOneElementContainingArrWhichIS_Minus1_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-1};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, std::vector<int>{-1});
}

TEST_P(IntSortTest, SortOneElementContainingArrWhichIS_67_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{67};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, std::vector<int>{67});
}

TEST_P(IntSortTest, SortOneElementContainingArrWhichIS_Minus67_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-67};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, std::vector<int>{-67});
}

TEST_P(IntSortTest, SortTwoElementContainingArr_0_0_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{0,0};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{0,0}));
}

TEST_P(IntSortTest, SortTwoSortedElementContainingArr_1_5_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{1,5};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{5,1}));
}

TEST_P(IntSortTest, SortTwoSortedElementContainingArr_5_1_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{5,1};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{5,1}));
}

TEST_P(IntSortTest, SortTwoSortedElementContainingArr_Minus5_Minus1_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-5,-1};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{-1,-5}));
}

TEST_P(IntSortTest, SortTwoSortedElementContainingArr_Minus1_Minus5_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-1,-5};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{-1,-5}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_5_Minus1_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{5,-1};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{5,-1}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_Minus1_5_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-1,5};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{5,-1}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_42_9_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{42,9};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{42,9}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_Minus9_Minus42_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-9,-42};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{-9,-42}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_6578_0_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{6578,0};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{6578,0}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_Minus6578_0_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-6578,0};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{0,-6578}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_0_Minus6578_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{0,-6578};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{0,-6578}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_0_6578_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{0,6578};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{6578,0}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_1_1_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{1,1};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{1,1}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_978512_978512_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{978512,978512};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{978512,978512}));
}

TEST_P(IntSortTest, SortTwoElementContainingArr_Minus978512_Minus978512_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-978512,-978512};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{-978512,-978512}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_0_0_0_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{0,0,0};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{0,0,0}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_4_42_986_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{4,42,986};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{986,42,4}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_42_4_986_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{42,4,986};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{986,42,4}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_42_986_4_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{42,986,4};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{986,42,4}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_986_42_4_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{986,42,4};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{986,42,4}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_986_4_42_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{986,4,42};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{986,42,4}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_4_986_42_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{4, 986, 42};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{986,42,4}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus986_4_42_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-986,4,42};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{42,4,-986}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_4_Minus986_42_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{4,-986,42};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{42,4,-986}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_4_42_Minus986_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{4,42,-986};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{42,4,-986}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_42_4_Minus986_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{42,4,-986};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{42,4,-986}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus986_Minus4_42_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-986,-4,42};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{42,-4,-986}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus4_Minus986_42_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-4,-986,42};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{42,-4,-986}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus986_4_Minus42_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-986,4,-42};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{4,-42,-986}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus42_4_Minus986_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-42,4,-986};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{4,-42,-986}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus986_Minus4_Minus42_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-986,-4,-42};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{-4,-42,-986}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus4_Minus986_Minus42_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-4,-986,-42};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{-4,-42,-986}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_0_Minus4_Minus42_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{0,-4,-42};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{0,-4,-42}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus4_0_Minus42_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-4,0,-42};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{0,-4,-42}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus4_Minus42_0_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-4,-42,0};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{0,-4,-42}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus42_Minus4_0_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-42,-4,0};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{0,-4,-42}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_15_15_15_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{15, 15, 15};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{15,15,15}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus15_Minus15_Minus15_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-15, -15, -15};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{-15,-15,-15}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus15_15_Minus15_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-15, 15, -15};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{15,-15,-15}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_15_Minus15_Minus15_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{15,-15,-15};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{15,-15,-15}));
}

TEST_P(IntSortTest, SortTreeElementContainingArr_Minus15_Minus15_15_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{-15,-15, 15};
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{15,-15,-15}));
}

TEST_P(IntSortTest, Sort_45_ElementContainingArrDescendingOrder)
{
    auto sort = GetParam();
    std::vector<int> arr{ 
            523, 87, 412, 9, 678, 234, 91, 345, 102, 789,
            56,  876, 321, 45, -6, -5, -4, -3, -2, -1, 678, 12, 999, 342, 65,
            123, 456, 789, 234, -100, -50, -10, -9, -8, -7, 
             87, 567, 890, 234, 345, 678,
            234, 56, 789, 234, 0
    };
    sort(arr.begin(), arr.end(), std::greater<int>{});
    EXPECT_EQ(arr, (std::vector<int>{
        999, 890, 876, 789, 789, 789, 678, 678, 678, 567,
        523, 456, 412, 345, 345, 342, 321, 234, 234, 234,
        234, 234, 123, 102, 91, 87, 87, 65, 56, 56,
        45, 12, 9, 0, -1, -2, -3, -4, -5, -6,
        -7, -8, -9, -10, -50, -100
    }));
}



//DoubleTest

using DoubleSortTest = TypedSortTest<double>;

INSTANTIATE_TEST_SUITE_P(
    IntSorts,
    DoubleSortTest,
    testing::Values(
        [](auto first, auto last, auto comp = std::less<>{}){ my_sort::bubble(first, last, comp); },
        [](auto first, auto last, auto comp = std::less<>{}){ my_sort::insertion(first, last, comp); },
        [](auto first, auto last, auto comp = std::less<>{}){ my_sort::selection(first, last, comp); },
        [](auto first, auto last, auto comp = std::less<>{}){ my_sort::merge_sort(first, last, comp); },
        [](auto first, auto last, auto comp = std::less<>{}){ my_sort::quick(first, last, comp); }
    )
        //[](auto first, auto last) { my_sort::quick(first, last); } 
);

TEST_P(DoubleSortTest, SortFourElementContainingArr_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<double> arr{0.0, -2.5, 3.0, -1.1};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<double>{-2.5, -1.1, 0.0, 3.0}));
}

TEST_P(DoubleSortTest, SortFiveElementContainingArr_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<double> arr{165.2, -3.2, 0.0, 5.5, -1.0};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<double>{-3.2, -1.0, 0.0, 5.5, 165.2}));
}

TEST_P(DoubleSortTest, SortSixElementContainingArr_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<double> arr{-10.0, 2.2, 0.01, -10.0, 3.3, -10.0};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<double>{-10.0, -10.0, -10.0, 0.01, 2.2, 3.3}));
}

TEST_P(DoubleSortTest, SortSevenElementContainingArr_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<double> arr{4.4, 0.999, -2.0, 4.4, 1.0, -3.3, 2.2};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<double>{-3.3, -2.0, 0.999, 1.0, 2.2, 4.4, 4.4}));
}

TEST_P(DoubleSortTest, SortEightElementContainingArr_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<double> arr{0.0, -1.1, 3.3, 2.2, -4.4, 5.5, -1.1, 4.4};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<double>{-4.4, -1.1, -1.1, 0.0, 2.2, 3.3, 4.4, 5.5}));
}

TEST_P(DoubleSortTest, SortNineElementContainingArr_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<double> arr{-5.5, 0.0, 1.1, 2.2, -3.3, 4.4, -5.5, 3.3, 0};
    sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, (std::vector<double>{-5.5, -5.5, -3.3, 0.0, 0, 1.1, 2.2, 3.3, 4.4}));
}

TEST_P(DoubleSortTest, SortTenElementContainingArr_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<double> arr{5.5, -1.1, 0.0, 3.3, -2.2, 2.2, -1.1, 1.1, 0.0, 4.4};
    sort(arr.begin(), arr.end(), std::less<>{});    
    EXPECT_EQ(arr, (std::vector<double>{-2.2, -1.1, -1.1, 0.0, 0.0, 1.1, 2.2, 3.3, 4.4, 5.5}));
}

TEST_P(DoubleSortTest, Sort_25_ElementContainingArr_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<double> arr{-12.5, 3.2, 0.0, 7.8, -1.0, 9.6, -4.4, 15.1, 6.3, -2.7,
    10.0, 8.8, 11.9, -0.5, 5.5, 14.2, -13.3, 7.0, 3.8, -6.1,
    2.2, 9.0, 4.9, 1.5, 12.0};
    sort(arr.begin(), arr.end(), std::less<>{});    
    EXPECT_EQ(arr, (std::vector<double>{-13.3, -12.5, -6.1, -4.4, -2.7, -1.0, -0.5, 0.0, 1.5, 2.2,
    3.2, 3.8, 4.9, 5.5, 6.3, 7.0, 7.8, 8.8, 9.0, 9.6,
    10.0, 11.9, 12.0, 14.2, 15.1}));
}

TEST_P(DoubleSortTest, Sort_68_ElementContainingArr_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<double> arr{45.3, -12.1, 0.0, 33.2, 7.5, -9.8, 22.4, 30.0, 18.5, -5.0,
    27.7, 11.0, 16.6, 40.2, -35.1, 28.8, 14.4, 21.9, 8.2, 36.7,
    -10.5, 6.6, 17.7, 25.0, 31.2, -19.8, 2.1, 23.4, 38.6, 13.2,
    15.0, -29.3, 26.1, 20.0, 1.5, 24.7, 39.0, 4.4, 34.5, 32.2,
    37.1, -41.6, 42.0, 43.5, 44.8, 46.2, -47.1, 48.0, 49.3, 50.0,
    -51.1, 52.5, 53.0, -54.6, 55.2, 56.0, -57.8, 58.3, 59.9, 60.0,
    61.2, -62.7, 63.5, 64.1, 65.0, -66.3, 67.7, 68.8};
    sort(arr.begin(), arr.end(), std::less<>{});    
    EXPECT_EQ(arr, (std::vector<double>{ -66.3, -62.7, -57.8, -54.6, -51.1, -47.1, -41.6, -35.1, -29.3, -19.8, 
    -12.1, -10.5, -9.8, -5.0, 0.0, 1.5, 2.1, 4.4, 6.6, 7.5, 
    8.2, 11.0, 13.2, 14.4, 15.0, 16.6, 17.7, 18.5, 20.0, 21.9, 
    22.4, 23.4, 24.7, 25.0, 26.1, 27.7, 28.8, 30.0, 31.2, 32.2, 
    33.2, 34.5, 36.7, 37.1, 38.6, 39.0, 40.2, 42.0, 43.5, 44.8, 
    45.3, 46.2, 48.0, 49.3, 50.0, 52.5, 53.0, 55.2, 56.0, 58.3, 
    59.9, 60.0, 61.2, 63.5, 64.1, 65.0, 67.7, 68.8}));
}

TEST_P(DoubleSortTest, Sort_100_ElementContainingArr_AscendingOrder)
{
    auto sort = GetParam();
    std::vector<double> arr{23.4, -45.2, 12.3, 0.0, 33.1, 41.7, -18.9, 29.0, 3.3, -50.5,
    21.1, 7.7, 36.4, -14.2, 48.6, 8.8, 25.6, -31.3, 10.0, 38.5,
    -2.2, 44.1, 16.6, -27.7, 11.1, 39.0, -4.4, 22.5, -37.7, 6.6,
    30.2, 19.3, -42.6, 13.5, 34.8, -9.9, 26.4, 17.5, 35.6, 1.1,
    -32.0, 24.8, 20.2, 40.1, 15.4, -28.8, 43.2, 49.9, -46.0, 47.3,
    51.2, -52.5, 53.0, 54.1, -55.6, 56.2, 57.3, -58.8, 59.0, 60.5,
    61.1, -62.7, 63.3, 64.0, 65.5, -66.2, 67.0, 68.5, -69.1, 70.0,
    71.3, 72.5, -73.0, 74.6, 75.2, 76.0, 77.8, -78.3, 79.9, 80.0,
    81.2, 82.7, -83.5, 84.1, 85.0, 86.3, 87.7, -88.8, 89.0, 90.5,
    91.1, -92.7, 93.3, 94.0, 95.5, -96.2, 97.0, 98.5, 99.1, 100.0};
    sort(arr.begin(), arr.end(), std::less<>{});    
    EXPECT_EQ(arr, (std::vector<double>{ -96.2, -92.7, -88.8, -83.5, -78.3, -73.0, -69.1, -66.2, -62.7, -58.8,
    -55.6, -52.5, -50.5, -46.0, -45.2, -42.6, -37.7, -32.0, -31.3, -28.8,
    -27.7, -18.9, -14.2, -9.9, -4.4, -2.2, 0.0, 1.1, 3.3, 6.6,
    7.7, 8.8, 10.0, 11.1, 12.3, 13.5, 15.4, 16.6, 17.5, 19.3,
    20.2, 21.1, 22.5, 23.4, 24.8, 25.6, 26.4, 29.0, 30.2, 33.1,
    34.8, 35.6, 36.4, 38.5, 39.0, 40.1, 41.7, 43.2, 44.1, 47.3,
    48.6, 49.9, 51.2, 53.0, 54.1, 56.2, 57.3, 59.0, 60.5, 61.1,
    63.3, 64.0, 65.5, 67.0, 68.5, 70.0, 71.3, 72.5, 74.6, 75.2,
    76.0, 77.8, 79.9, 80.0, 81.2, 82.7, 84.1, 85.0, 86.3, 87.7,
    89.0, 90.5, 91.1, 93.3, 94.0, 95.5, 97.0, 98.5, 99.1, 100.0}));
}

TEST_P(DoubleSortTest, SortFourElementContainingArr_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<double> arr{0.0, -2.5, 3.0, -1.1};
    sort(arr.begin(), arr.end(), std::greater<double>{});
    EXPECT_EQ(arr, (std::vector<double>{3.0, 0.0, -1.1, -2.5}));
}

TEST_P(DoubleSortTest, SortFiveElementContainingArr_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<double> arr{165.2, -3.2, 0.0, 5.5, -1.0};
    sort(arr.begin(), arr.end(), std::greater<double>{});
    EXPECT_EQ(arr, (std::vector<double>{165.2, 5.5, 0.0, -1.0, -3.2}));
}

TEST_P(DoubleSortTest, SortSixElementContainingArr_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<double> arr{-10.0, 2.2, 0.01, -10.0, 3.3, -10.0};
    sort(arr.begin(), arr.end(), std::greater<double>{});
    EXPECT_EQ(arr, (std::vector<double>{3.3, 2.2, 0.01, -10.0, -10.0, -10.0}));
}

TEST_P(DoubleSortTest, SortSevenElementContainingArr_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<double> arr{4.4, 0.999, -2.0, 4.4, 1.0, -3.3, 2.2};
    sort(arr.begin(), arr.end(), std::greater<double>{});
    EXPECT_EQ(arr, (std::vector<double>{4.4, 4.4, 2.2, 1.0, 0.999, -2.0, -3.3}));
}

TEST_P(DoubleSortTest, SortEightElementContainingArr_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<double> arr{0.0, -1.1, 3.3, 2.2, -4.4, 5.5, -1.1, 4.4};
    sort(arr.begin(), arr.end(), std::greater<double>{});
    EXPECT_EQ(arr, (std::vector<double>{5.5, 4.4, 3.3, 2.2, 0.0, -1.1, -1.1, -4.4}));
}

TEST_P(DoubleSortTest, SortNineElementContainingArr_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<double> arr{-5.5, 0.0, 1.1, 2.2, -3.3, 4.4, -5.5, 3.3, 0};
    sort(arr.begin(), arr.end(), std::greater<double>{});
    EXPECT_EQ(arr, (std::vector<double>{4.4, 3.3, 2.2, 1.1, 0.0, 0, -3.3, -5.5, -5.5}));
}

TEST_P(DoubleSortTest, SortTenElementContainingArr_DescendingOrder)
{
    auto sort = GetParam();
    std::vector<double> arr{5.5, -1.1, 0.0, 3.3, -2.2, 2.2, -1.1, 1.1, 0.0, 4.4};
    sort(arr.begin(), arr.end(), std::greater<double>{});    
    EXPECT_EQ(arr, (std::vector<double>{5.5, 4.4, 3.3, 2.2, 1.1, 0.0, 0.0, -1.1, -1.1, -2.2}));
}