#include <vector>
#include <gtest/gtest.h>
#include "../include/searching_lib/my_search.hpp"
#include "../include/sorting_lib/my_sort.hpp"

template<typename T>
class TypedSearchTest : public testing::TestWithParam<
    std::function<typename std::vector<T>::iterator(typename std::vector<T>::iterator,
        typename std::vector<T>::iterator, const T&)>> {};

using IntSearchTest = TypedSearchTest<int>;

INSTANTIATE_TEST_SUITE_P(
    IntSearch,
    IntSearchTest,
    testing::Values(
        [](auto first, auto last, auto value){ return my_search::linear(first, last, value); 
        }
    )
);

TEST_P(IntSearchTest, Search_0_FromEmptyArray)
{
    auto search = GetParam();
    std::vector<int> arr;
    auto res = search(arr.begin(), arr.end(), 0);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTest, Search_1_FromEmptyArray)
{
    auto search = GetParam();
    std::vector<int> arr;
    auto res = search(arr.begin(), arr.end(), 1);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTest, Search_Minus1_FromEmptyArray)
{
    auto search = GetParam();
    std::vector<int> arr;
    auto res = search(arr.begin(), arr.end(), -1);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTest, Search_0_FromOneElementContainingArr_0)
{
    auto search = GetParam();
    std::vector<int> arr(1);
    auto res = search(arr.begin(), arr.end(), 0);
    EXPECT_EQ(res, arr.begin());
}

TEST_P(IntSearchTest, Search_1_FromOneElementContainingArr_0)
{
    auto search = GetParam();
    std::vector<int> arr(1);
    auto res = search(arr.begin(), arr.end(), 1);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTest, Search_Minus72_FromOneElementContainingArr_0)
{
    auto search = GetParam();
    std::vector<int> arr(1);
    auto res = search(arr.begin(), arr.end(), -72);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTest, Search_Minus72_FromOneElementContainingArr_Minus72)
{
    auto search = GetParam();
    std::vector<int> arr{-72};
    auto res = search(arr.begin(), arr.end(), -72);
    EXPECT_EQ(res, arr.begin());
}

TEST_P(IntSearchTest, Search_0_FromTwoElementContainingArr_0_0)
{
    auto search = GetParam();
    std::vector<int> arr{0,0};
    auto res = search(arr.begin(), arr.end(), 0);
    EXPECT_EQ(res, arr.begin());
}

TEST_P(IntSearchTest, Search_526_FromTwoElementContainingArr_0_1)
{
    auto search = GetParam();
    std::vector<int> arr{0,1};
    auto res = search(arr.begin(), arr.end(), 526);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTest, Search_0_FromTwoElementContainingArr_0_1)
{
    auto search = GetParam();
    std::vector<int> arr{0,1};
    auto res = search(arr.begin(), arr.end(), 0);
    EXPECT_EQ(res, arr.begin());
}

TEST_P(IntSearchTest, Search_1_FromTwoElementContainingArr_0_1)
{
    auto search = GetParam();
    std::vector<int> arr{0,1};
    auto res = search(arr.begin(), arr.end(), 1);
    EXPECT_EQ(res, arr.begin() + 1);
}

TEST_P(IntSearchTest, Search_0_FromTwoElementContainingArr_1_0)
{
    auto search = GetParam();
    std::vector<int> arr{1,0};
    auto res = search(arr.begin(), arr.end(), 0);
    EXPECT_EQ(res, arr.begin() + 1);
}

TEST_P(IntSearchTest, Search_1_FromTwoElementContainingArr_1_0)
{
    auto search = GetParam();
    std::vector<int> arr{1,0};
    auto res = search(arr.begin(), arr.end(), 1);
    EXPECT_EQ(res, arr.begin());
}

TEST_P(IntSearchTest, Search_Minus7591_FromTwoElementContainingArr_1_0)
{
    auto search = GetParam();
    std::vector<int> arr{1,0};
    auto res = search(arr.begin(), arr.end(), -7591);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTest, Search_3_FromTwoElementContainingArr_3_3)
{
    auto search = GetParam();
    std::vector<int> arr{3,3};
    auto res = search(arr.begin(), arr.end(), 3);
    EXPECT_EQ(res, arr.begin());
}

TEST_P(IntSearchTest, Search_0_FromTreeElementContainingArr_12_32_7)
{
    auto search = GetParam();
    std::vector<int> arr{12,32, 7};
    auto res = search(arr.begin(), arr.end(), 0);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTest, Search_Minus98_FromTreeElementContainingArr_12_32_7)
{
    auto search = GetParam();
    std::vector<int> arr{12,32, 7};
    auto res = search(arr.begin(), arr.end(), -98);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTest, Search_12_FromTreeElementContainingArr_12_32_7)
{
    auto search = GetParam();
    std::vector<int> arr{12,32, 7};
    auto res = search(arr.begin(), arr.end(), 12);
    EXPECT_EQ(res, arr.begin());
}

TEST_P(IntSearchTest, Search_32_FromTreeElementContainingArr_12_32_7)
{
    auto search = GetParam();
    std::vector<int> arr{12,32, 7};
    auto res = search(arr.begin(), arr.end(), 32);
    EXPECT_EQ(res, arr.begin() + 1);
}

TEST_P(IntSearchTest, Search_7_FromTreeElementContainingArr_12_32_7)
{
    auto search = GetParam();
    std::vector<int> arr{12,32, 7};
    auto res = search(arr.begin(), arr.end(), 7);
    EXPECT_EQ(res, arr.begin() + 2);
}

TEST_P(IntSearchTest, Search_7_FromTreeElementContainingArr_7_32_7)
{
    auto search = GetParam();
    std::vector<int> arr{7,32, 7};
    auto res = search(arr.begin(), arr.end(), 7);
    EXPECT_EQ(res, arr.begin());
}

TEST_P(IntSearchTest, Search_32_FromTreeElementContainingArr_7_32_7)
{
    auto search = GetParam();
    std::vector<int> arr{7,32, 7};
    auto res = search(arr.begin(), arr.end(), 32);
    EXPECT_EQ(res, arr.begin() + 1);
}

TEST_P(IntSearchTest, Search_7_FromTreeElementContainingArr_0_7_7)
{
    auto search = GetParam();
    std::vector<int> arr{0,7,7};
    auto res = search(arr.begin(), arr.end(), 7);
    EXPECT_EQ(res, arr.begin() + 1);
}

TEST_P(IntSearchTest, Search_5_FromFourElementArr_1_5_9_11)
{
    auto search = GetParam();
    std::vector<int> arr{1, 5, 9, 11};
    auto res = search(arr.begin(), arr.end(), 5);
    EXPECT_EQ(res, arr.begin() + 1);
}

TEST_P(IntSearchTest, Search_10_FromFiveElementArr_2_4_6_8_10)
{
    auto search = GetParam();
    std::vector<int> arr{2, 4, 6, 8, 10};
    auto res = search(arr.begin(), arr.end(), 10);
    EXPECT_EQ(res, arr.begin() + 4);
}

TEST_P(IntSearchTest, Search_3_FromSixElementArr_3_3_3_3_3_3)
{
    auto search = GetParam();
    std::vector<int> arr{3, 3, 3, 3, 3, 3};
    auto res = search(arr.begin(), arr.end(), 3);
    EXPECT_EQ(res, arr.begin());
}

TEST_P(IntSearchTest, Search_7_FromSevenElementArr_2_2_9_7_4_7_6)
{
    auto search = GetParam();
    std::vector<int> arr{2, 2, 9, 7, 4, 5, 6};
    auto res = search(arr.begin(), arr.end(), 7);
    EXPECT_EQ(res, arr.begin() + 3); 
}

TEST_P(IntSearchTest, Search_42_FromThirteenElementArr)
{
    auto search = GetParam();
    std::vector<int> arr{1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 42};
    auto res = search(arr.begin(), arr.end(), 42);
    EXPECT_EQ(res, arr.begin() + 12);
}

TEST_P(IntSearchTest, Search_17_FromFortyOneElementArr)
{
    auto search = GetParam();
    std::vector<int> arr{5, 3, 77, 9, 1, 12, 4, 8, 17, 2, 9, 17, 6, 11, 17, 7, 3, 10, 5, 12, 17, 13, 8, 14, 17, 15, 4, 16, 9, 17, 18, 17, 19, 17, 20, 17, 21, 17, 22, 17, 23};
    auto res = search(arr.begin(), arr.end(), 17);
    EXPECT_EQ(res, arr.begin() + 8); 
}

TEST_P(IntSearchTest, Search_500_FromHundredElementArr_NotFound)
{
    auto search = GetParam();
    std::vector<int> arr{7, 14, 22, 5, 9, 13, 7, 1, 4, 15, 16, 22, 25, 17, 14, 7, 9, 12, 30, 40, 50, 10, 12, 13, 14, 7, 3, 17, 18, 25, 25, 7, 33, 45, 60, 70, 80, 22, 7, 3, 6, 9, 11, 13, 15, 17, 18, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 55, 57, 59, 60, 65, 67, 68, 70, 75, 77, 78, 80, 83, 85, 87, 90, 91, 92, 93, 95, 96, 97, 99};
    auto res = search(arr.begin(), arr.end(), 500);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTest, Search_Minus77_FromHundredFiftyElementArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{
    1, 4, 7, 7, 12, 15, 18, 21, 24, 27, 30, 33, 7, 36, 39, 42, 45, 48, 51, 54,
    57, 60, 63, 66, 7, 69, 72, 75, 77, 80, 83, 7, 86, 89, 92, 95, 98, 7, 11, -77,
    17, 20, 23, 26, 29, 32, 35, 38, 7, 41, 44, 47, 50, 53, 56, 59, 62, 65, 68, 71,
    74, -77, 79, 82, 85, 88, 91, 94, 97, 7, 99, 100, 7, 101, 102, 7, 103, 104, 7, 105,
    106, 7, 107, 108, 7, 109, 110, 7, 111, 112, 7, 113, 114, 115, 116, 117, 118, 119, 120, 7,
    121, 122, 123, 124, 125, 126, 127, 7, 128, 129, 130, 131, 132, 133, 134, -77, 135, 136, 137, 138,
    139, 140, 141, 142, 143, 144, 145, 7, 146, 147, 148, 149, 150, 151, -77, 152, 153, 154, 155, 156,
    157, 158, 159, 160, 161, 162, 163, 164, 165, 166
    };

    auto res = search(arr.begin(), arr.end(), -77);
    EXPECT_EQ(res, arr.begin() + 39);
}

using IntSearchTestWithSortedArray = TypedSearchTest<int>;

INSTANTIATE_TEST_SUITE_P(
    IntSearch,
    IntSearchTestWithSortedArray,
    testing::Values(
        [](auto first, auto last, auto value){ return my_search::binary(first, last, value); },
        [](auto first, auto last, auto value){ return my_search::jump(first, last, value); }
    )
);

TEST_P(IntSearchTestWithSortedArray, Search_0_FromEmptyArray)
{
    auto search = GetParam();
    std::vector<int> arr;
    auto res = search(arr.begin(), arr.end(), 0);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTestWithSortedArray, Search_1_FromEmptyArray)
{
    auto search = GetParam();
    std::vector<int> arr;
    auto res = search(arr.begin(), arr.end(), 1);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTestWithSortedArray, Search_Minus1_FromEmptyArray)
{
    auto search = GetParam();
    std::vector<int> arr;
    auto res = search(arr.begin(), arr.end(), -1);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTestWithSortedArray, Search_0_FromOneElementContainingArr_0)
{
    auto search = GetParam();
    std::vector<int> arr(1);
    auto res = search(arr.begin(), arr.end(), 0);
    EXPECT_EQ(res, arr.begin());
}

TEST_P(IntSearchTestWithSortedArray, Search_1_FromOneElementContainingArr_0)
{
    auto search = GetParam();
    std::vector<int> arr(1);
    auto res = search(arr.begin(), arr.end(), 1);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTestWithSortedArray, Search_Minus72_FromOneElementContainingArr_0)
{
    auto search = GetParam();
    std::vector<int> arr(1);
    auto res = search(arr.begin(), arr.end(), -72);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTestWithSortedArray, Search_Minus72_FromOneElementContainingArr_Minus72)
{
    auto search = GetParam();
    std::vector<int> arr{-72};
    auto res = search(arr.begin(), arr.end(), -72);
    EXPECT_EQ(res, arr.begin());
}

TEST_P(IntSearchTestWithSortedArray, Search_0_FromTwoElementContainingArr_0_0)
{
    auto search = GetParam();
    std::vector<int> arr{0,0};
    auto res = search(arr.begin(), arr.end(), 0);
    EXPECT_EQ(res, arr.begin());
}

TEST_P(IntSearchTestWithSortedArray, Search_526_FromTwoElementContainingArr_0_1)
{
    auto search = GetParam();
    std::vector<int> arr{0,1};
    auto res = search(arr.begin(), arr.end(), 526);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTestWithSortedArray, Search_0_FromTwoElementContainingArr_0_1)
{
    auto search = GetParam();
    std::vector<int> arr{0,1};
    auto res = search(arr.begin(), arr.end(), 0);
    EXPECT_EQ(res, arr.begin());
}

TEST_P(IntSearchTestWithSortedArray, Search_1_FromTwoElementContainingArr_0_1)
{
    auto search = GetParam();
    std::vector<int> arr{0,1};
    auto res = search(arr.begin(), arr.end(), 1);
    EXPECT_EQ(res, arr.begin() + 1);
}

TEST_P(IntSearchTestWithSortedArray, Search_3_FromTwoElementContainingArr_3_3)
{
    auto search = GetParam();
    std::vector<int> arr{3,3};
    auto res = search(arr.begin(), arr.end(), 3);
    EXPECT_EQ(res, arr.begin());
}

TEST_P(IntSearchTestWithSortedArray, Search_0_FromTreeElementContainingArr_7_12_32)
{
    auto search = GetParam();
    std::vector<int> arr{7,12,32};
    auto res = search(arr.begin(), arr.end(), 0);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTestWithSortedArray, Search_7_FromTreeElementContainingArr_7_12_32)
{
    auto search = GetParam();
    std::vector<int> arr{7,12,32};
    auto res = search(arr.begin(), arr.end(), 7);
    EXPECT_EQ(res, arr.begin());
}

TEST_P(IntSearchTestWithSortedArray, Search_12_FromTreeElementContainingArr_7_12_32)
{
    auto search = GetParam();
    std::vector<int> arr{7,12,32};
    auto res = search(arr.begin(), arr.end(), 12);
    EXPECT_EQ(res, arr.begin() + 1);
}

TEST_P(IntSearchTestWithSortedArray, Search_32_FromTreeElementContainingArr_7_12_32)
{
    auto search = GetParam();
    std::vector<int> arr{7,12,32};
    auto res = search(arr.begin(), arr.end(), 32);
    EXPECT_EQ(res, arr.begin() + 2);
}

TEST_P(IntSearchTestWithSortedArray, Search_Minus896_FromTreeElementContainingArr_7_12_32)
{
    auto search = GetParam();
    std::vector<int> arr{7,12,32};
    auto res = search(arr.begin(), arr.end(), -896);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTestWithSortedArray, Search_12_FromTreeElementContainingArr_7_12_12)
{
    auto search = GetParam();
    std::vector<int> arr{7,12,12};
    auto res = search(arr.begin(), arr.end(), 12);
    EXPECT_EQ(res, arr.begin() + 1);
}

TEST_P(IntSearchTestWithSortedArray, Search_5_FromFourElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{-4,5,12,18};
    auto res = search(arr.begin(), arr.end(), 5);
    EXPECT_EQ(res, arr.begin() + 1);
}

TEST_P(IntSearchTestWithSortedArray, Search_FromFourElementContainingArr_NotFound)
{
    auto search = GetParam();
    std::vector<int> arr{-7,2,2,15};
    auto res = search(arr.begin(), arr.end(), 10);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTestWithSortedArray, Search_8_FromFiveElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{-2,0,8,8,20};
    auto res = search(arr.begin(), arr.end(), 8);
    EXPECT_EQ(res, arr.begin() + 2);
}

TEST_P(IntSearchTestWithSortedArray, Search_4_FromFiveElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{-3,1,3,4,9};
    auto res = search(arr.begin(), arr.end(), 4);
    EXPECT_EQ(res, arr.begin() + 3);
}

TEST_P(IntSearchTestWithSortedArray, Search_5_FromSixElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{-8,-2,0,2,5,12};
    auto res = search(arr.begin(), arr.end(), 5);
    EXPECT_EQ(res, arr.begin() + 4);
}

TEST_P(IntSearchTestWithSortedArray, Search_Minus3_FromSixElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{-34,-5,-3,-3,9,15};
    auto res = search(arr.begin(), arr.end(), -3);
    EXPECT_EQ(res, arr.begin() + 2);
}

TEST_P(IntSearchTestWithSortedArray, Search_77_FromSevenElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{-10,-4,2,10,11,18,77};
    auto res = search(arr.begin(), arr.end(), 77);
    EXPECT_EQ(res, arr.begin() + 6);
}

TEST_P(IntSearchTestWithSortedArray, Search_17_FromSevenElementContainingArr_NotFound)
{
    auto search = GetParam();
    std::vector<int> arr{-12,-5,2,3,6,11,16};
    auto res = search(arr.begin(), arr.end(), 17);
    EXPECT_EQ(res, arr.end());
}

TEST_P(IntSearchTestWithSortedArray, Search_1_FromEightElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{-6,1,1,8,13,22,22,30};
    auto res = search(arr.begin(), arr.end(), 1);
    EXPECT_EQ(res, arr.begin() + 1);
}

TEST_P(IntSearchTestWithSortedArray, Search_2_FromEightElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{-15,-9,-3,-1,1,1,2,20};
    auto res = search(arr.begin(), arr.end(), 2);
    EXPECT_EQ(res, arr.begin() + 6);
}

TEST_P(IntSearchTestWithSortedArray, Search_Minus1_FromNineElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{-15,-8, -1,-1,4,10,17,24,31};
    auto res = search(arr.begin(), arr.end(), -1);
    EXPECT_EQ(res, arr.begin() + 2);
}

TEST_P(IntSearchTestWithSortedArray, Search_1000_FromNineElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{-20,-13,-6,1,1,8,15,1000,3000};
    auto res = search(arr.begin(), arr.end(), 1000);
    EXPECT_EQ(res, arr.begin() + 7);
}

TEST_P(IntSearchTestWithSortedArray, Search_42_FromEighteenElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{-20,-14,-7,0,5,8,12,15,18,22,25,28,33,37,42,47,51,56};
    auto res = search(arr.begin(), arr.end(), 42);
    EXPECT_EQ(res, arr.begin() + 14);
}

TEST_P(IntSearchTestWithSortedArray, Search_19_FromTwentySixElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{-25,-18,-12,-5,1,4,7,10,13,16,19,21,24,27,30,33,36,39,42,45,48,51,54,57,60};
    auto res = search(arr.begin(), arr.end(), 19);
    EXPECT_EQ(res, arr.begin() + 10);
}

TEST_P(IntSearchTestWithSortedArray, Search_34_FromThirtyFourElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{-50,-40,-30,-20,-10,0,5,8,12,15,18,22,25,28,31,34,37,40,43,46,49,52,55,58,61,64,67,70,73,76,79,82,85,88};
    auto res = search(arr.begin(), arr.end(), 34);
    EXPECT_EQ(res, arr.begin() + 15);
}

TEST_P(IntSearchTestWithSortedArray, Search_28_FromFiftyFiveElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{-100,-80,-60,-40,-20,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100};
    auto res = search(arr.begin(), arr.end(), 28);
    EXPECT_EQ(res, arr.begin() + 19);
}

TEST_P(IntSearchTestWithSortedArray, Search_65_FromSeventyNineElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{-150,-120,-90,-60,-30,0,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54,57,60,63,65,68,71,74,77,80,83,86,89,92,95,98,101,104,107,110,113,116,119,122,125,128,131,134,137,140,143,146,149,152,155,158,161,164,167,170,173,176,179,182,185,188,191,194,197,200};
    auto res = search(arr.begin(), arr.end(), 65);
    EXPECT_EQ(res, arr.begin() + 27);
}

TEST_P(IntSearchTestWithSortedArray, Search_47_FromNinetyOneElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{-200,-180,-160,-140,-120,-100,-80,-60,-40,-20,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,47,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,160};
    auto res = search(arr.begin(), arr.end(), 47);
    EXPECT_EQ(res, arr.begin() + 34);
}

TEST_P(IntSearchTestWithSortedArray, Search_85_FromOneHundredTwoElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{-250,-220,-190,-160,-130,-100,-70,-40,-10,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175,180,185,190,195,200,205,210,215,220,225,230,235,240,245,250,255,260,265,270,275,280,285,290,295,300,305,310,315,320,325,330,335,340,345,350,355,360,365,370,375,380,385,390,395,400,405,410,415,420,425,430,435,440,445,450};
    auto res = search(arr.begin(), arr.end(), 85);
    EXPECT_EQ(res, arr.begin() + 22);
}

TEST_P(IntSearchTestWithSortedArray, Search_95_FromOneHundredTwentyElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr{-300,-270,-240,-210,-180,-150,-120,-90,-60,-30,0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175,180,185,190,195,200,205,210,215,220,225,230,235,240,245,250,255,260,265,270,275,280,285,290,295,300,305,310,315,320,325,330,335,340,345,350,355,360,365,370,375,380,385,390,395,400,405,410,415,420,425,430,435,440,445,450,455,460,465,470,475,480,485,490,495,500};
    auto res = search(arr.begin(), arr.end(), 95);
    EXPECT_EQ(res, arr.begin() + 29);
}

TEST_P(IntSearchTestWithSortedArray, Search_0_FromTwoHundredElementContainingArr_Found)
{
    auto search = GetParam();
    std::vector<int> arr;
    for(int i = -500; i < 500; i += 5) arr.push_back(i);
    auto res = search(arr.begin(), arr.end(), 0);
    EXPECT_EQ(res, arr.begin() + 100);
}

TEST_P(IntSearchTestWithSortedArray, Search_600_FromOneHundredTwentyElementContainingArr_NotFound)
{
    auto search = GetParam();
    std::vector<int> arr{-300,-270,-240,-210,-180,-150,-120,-90,-60,-30,0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175,180,185,190,195,200,205,210,215,220,225,230,235,240,245,250,255,260,265,270,275,280,285,290,295,300,305,310,315,320,325,330,335,340,345,350,355,360,365,370,375,380,385,390,395,400,405,410,415,420,425,430,435,440,445,450,455,460,465,470,475,480,485,490,495,500};
    auto res = search(arr.begin(), arr.end(), 600);
    EXPECT_EQ(res, arr.end());
}


//Interpolation
TEST(InterpolationSearchTest, Search_0_FromEmptyArray)
{
    std::vector<int> arr;
    auto res = my_search::interpolation(arr.begin(), arr.end(), 0);
    EXPECT_EQ(res, arr.end());
}

TEST(InterpolationSearchTest, Search_1_FromOneElementContainingArr_1)
{
    std::vector<int> arr{1};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 1);
    EXPECT_EQ(res, arr.begin());
}

TEST(InterpolationSearchTest, Search_5_FromOneElementContainingArr_1)
{
    std::vector<int> arr{1};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 5);
    EXPECT_EQ(res, arr.end());
}

TEST(InterpolationSearchTest, Search_0_FromTwoElementContainingArr_0_5)
{
    std::vector<int> arr{0,5};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 0);
    EXPECT_EQ(res, arr.begin());
}

TEST(InterpolationSearchTest, Search_5_FromTwoElementContainingArr_0_5)
{
    std::vector<int> arr{0,5};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 5);
    EXPECT_EQ(res, arr.begin() + 1);
}

TEST(InterpolationSearchTest, Search_3_FromTwoElementContainingArr_0_5)
{
    std::vector<int> arr{0,5};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 3);
    EXPECT_EQ(res, arr.end());
}

TEST(InterpolationSearchTest, Search_Minus7_FromTwoElementContainingArr_Minus7_Minus7)
{
    std::vector<int> arr{-7,-7};
    auto res = my_search::interpolation(arr.begin(), arr.end(), -7);
    EXPECT_EQ(res, arr.begin());
}

TEST(InterpolationSearchTest, Search_10_FromThreeElementContainingArr_10_20_30)
{
    std::vector<int> arr{10,20,30};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 10);
    EXPECT_EQ(res, arr.begin());
}

TEST(InterpolationSearchTest, Search_20_FromThreeElementContainingArr_10_20_30)
{
    std::vector<int> arr{10,20,30};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 20);
    EXPECT_EQ(res, arr.begin() + 1);
}

TEST(InterpolationSearchTest, Search_30_FromThreeElementContainingArr_10_20_30)
{
    std::vector<int> arr{10,20,30};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 30);
    EXPECT_EQ(res, arr.begin() + 2);
}

TEST(InterpolationSearchTest, Search_25_FromThreeElementContainingArr_10_20_30)
{
    std::vector<int> arr{10,20,30};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 25);
    EXPECT_EQ(res, arr.end());
}

TEST(InterpolationSearchTest, Search_15_FromFiveElementContainingArr_0_5_10_15_20)
{
    std::vector<int> arr{0,5,10,15,20};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 15);
    EXPECT_EQ(res, arr.begin() + 3);
}

TEST(InterpolationSearchTest, Search_2_FromFiveElementContainingArr_0_5_10_15_20)
{
    std::vector<int> arr{0,5,10,15,20};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 2);
    EXPECT_EQ(res, arr.end());
}

TEST(InterpolationSearchTest, Search_50_FromTenElementArr_Found)
{
    std::vector<int> arr;
    for (int i = 0; i < 100; i += 10) 
        arr.push_back(i);
    auto res = my_search::interpolation(arr.begin(), arr.end(), 50);
    EXPECT_EQ(res, arr.begin() + 5);
}

TEST(InterpolationSearchTest, Search_75_FromTenElementArr_NotFound)
{
    std::vector<int> arr;
    for (int i = 0; i < 100; i += 10) 
        arr.push_back(i);
    auto res = my_search::interpolation(arr.begin(), arr.end(), 75);
    EXPECT_EQ(res, arr.end());
}

TEST(InterpolationSearchTest, Search_100_FromTwentyElementArr_Found)
{
    std::vector<int> arr;
    for (int i = 0; i <= 190; i += 10)
        arr.push_back(i);
    auto res = my_search::interpolation(arr.begin(), arr.end(), 100);
    EXPECT_EQ(res, arr.begin() + 10);
}

TEST(InterpolationSearchTest, Search_185_FromTwentyElementArr_NotFound)
{
    std::vector<int> arr;
    for (int i = 0; i <= 190; i += 10) 
        arr.push_back(i);
    auto res = my_search::interpolation(arr.begin(), arr.end(), 185);
    EXPECT_EQ(res, arr.end());
}

TEST(InterpolationSearchTest, Search_Minus2_FromFiftyElementArr_Found)
{
    std::vector<int> arr;
    for (int i = -100; i < 250; i += 7) 
        arr.push_back(i);
    auto res = my_search::interpolation(arr.begin(), arr.end(), -2);
    EXPECT_EQ(res, arr.begin() + 14);
}

TEST(InterpolationSearchTest, Search_540_FromOneHundredElementContainingArr_Found)
{
    std::vector<int> arr;
    for (int i = 0; i < 2700; i += 27) 
        arr.push_back(i);
    auto res = my_search::interpolation(arr.begin(), arr.end(), 540);
    EXPECT_EQ(res, arr.begin() + 20);
}

TEST(InterpolationSearchTest, Search_600_FromOneHundredTwentyElementContainingArr_NotFound)
{
    std::vector<int> arr;
    for (int i = -300; i <= 300; i += 5) 
        arr.push_back(i);
    auto res = my_search::interpolation(arr.begin(), arr.end(), 600);
    EXPECT_EQ(res, arr.end());
}

TEST(InterpolationSearchTest, Search_0_FromTwoHundredElementContainingArr_Found)
{
    std::vector<int> arr;
    for (int i = -500; i < 500; i += 5) 
        arr.push_back(i);
    auto res = my_search::interpolation(arr.begin(), arr.end(), 0);
    EXPECT_EQ(res, arr.begin() + 100);
}

TEST(InterpolationSearchTest, Search_5_FromNineteenElementContainingArr_Found)
{
    std::vector<int> arr = {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 5);
    EXPECT_EQ(res, arr.begin());
}


//Non-Uniform distributive elements
TEST(InterpolationSearchTest, Search_Minus98_FromTreeElementContainingArr_7_12_37)
{
    std::vector<int> arr{7,12,37};
    auto res = my_search::interpolation(arr.begin(), arr.end(), -98);
    EXPECT_EQ(res, arr.end());
}

TEST(InterpolationSearchTest, Search_7_FromTreeElementContainingArr_7_12_37)
{
    std::vector<int> arr{7,12,37};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 7);
    EXPECT_EQ(res, arr.begin());
}

TEST(InterpolationSearchTest, Search_12_FromTreeElementContainingArr_7_12_37)
{
    std::vector<int> arr{7,12,37};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 12);
    EXPECT_EQ(res, arr.begin() + 1);
}

TEST(InterpolationSearchTest, Search_32_FromTreeElementContainingArr_7_12_37)
{
    std::vector<int> arr{7,12,37};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 37);
    EXPECT_EQ(res, arr.begin() + 2);
}

TEST(InterpolationSearchTest, Search_8_FromFiveElementContainingArr_Found)
{
    std::vector<int> arr{-2,0,8,15,20};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 8);
    EXPECT_EQ(res, arr.begin() + 2);
}

TEST(InterpolationSearchTest, Search_4_FromFiveElementContainingArr_Found)
{
    std::vector<int> arr{-3,1,3,4,9};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 4);
    EXPECT_EQ(res, arr.begin() + 3);
}

TEST(InterpolationSearchTest, Search_5_FromSixElementContainingArr_Found)
{
    std::vector<int> arr{-8,-2,0,4,5,12};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 5);
    EXPECT_EQ(res, arr.begin() + 4);
}

TEST(InterpolationSearchTest, Search_77_FromSevenElementContainingArr_Found)
{
    std::vector<int> arr{-10,-4,2,10,11,18,77};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 77);
    EXPECT_EQ(res, arr.begin() + 6);
}

TEST(InterpolationSearchTest, Search_17_FromSevenElementContainingArr_NotFound)
{
    std::vector<int> arr{-12,-5,2,3,6,11,16};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 17);
    EXPECT_EQ(res, arr.end());
}

TEST(InterpolationSearchTest, Search_Minus1_FromNineElementContainingArr_Found)
{
    std::vector<int> arr{-15,-8, -1,0,4,10,17,24,31};
    auto res = my_search::interpolation(arr.begin(), arr.end(), -1);
    EXPECT_EQ(res, arr.begin() + 2);
}

TEST(InterpolationSearchTest, Search_42_FromEighteenElementContainingArr_Found)
{
    std::vector<int> arr{-20,-14,-7,0,5,8,12,15,18,22,25,28,33,37,42,47,51,56};
    auto res = my_search::interpolation(arr.begin(), arr.end(), 42);
    EXPECT_EQ(res, arr.begin() + 14);
}

TEST(InterpolationSearchTest, SearchsFromTwoHundredElementContainingArr)
{
    std::vector<int> arr = {
        -998, -985, -971, -959, -946, -932, -918, -905, -890, -876,
        -861, -849, -837, -822, -810, -796, -783, -768, -754, -739,
        -727, -713, -700, -687, -673, -660, -646, -633, -619, -606,
        -592, -580, -565, -552, -540, -525, -513, -499, -486, -472,
        -458, -445, -432, -419, -405, -392, -378, -365, -351, -338,
        -324, -310, -297, -283, -270, -256, -243, -229, -216, -202,
        -188, -175, -162, -148, -135, -121, -108, -94,  -81,  -67,
        -54,  -40,  -27,  -13,  0,    14,   27,   41,   54,   68,
        82,   95,   109,  122,  136,  149,  163,  176,  190,  203,
        217,  230,  244,  258,  271,  285,  298,  312,  325,  339,
        352,  366,  379,  393,  407,  420,  434,  447,  461,  474,
        488,  501,  515,  528,  542,  555,  569,  582,  596,  610,
        623,  637,  650,  664,  677,  691,  704,  718,  731,  745,
        758,  772,  786,  799,  813,  826,  840,  853,  867,  880,
        894,  908,  921,  935,  948,  962,  975,  989,  1002, 1016,
        1029, 1043, 1056, 1070, 1083, 1097, 1110, 1124, 1137, 1151,
        1164, 1178, 1192, 1205, 1219, 1232, 1246, 1259, 1273, 1286
    };

    EXPECT_EQ(my_search::interpolation(arr.begin(), arr.end(), 0), arr.begin() + 74);
    EXPECT_EQ(my_search::interpolation(arr.begin(), arr.end(), -998), arr.begin());
    EXPECT_EQ(my_search::interpolation(arr.begin(), arr.end(), 1286), arr.end() - 1);
    EXPECT_EQ(my_search::interpolation(arr.begin(), arr.end(), 582), arr.begin() + 117);
    EXPECT_EQ(my_search::interpolation(arr.begin(), arr.end(), -3000), arr.end()); 
    EXPECT_EQ(my_search::interpolation(arr.begin(), arr.end(), 2000), arr.end()); 
}