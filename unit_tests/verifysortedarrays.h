#ifndef SORTING_UNIT_TESTS_VERIFYSORTEDARRAYS_H_
#define SORTING_UNIT_TESTS_VERIFYSORTEDARRAYS_H_

#include "gtest/gtest.h"


#define VALIDATE_SORTING(to_sort_data, sorted_data, N)                  \
{                                                                       \
    for (int i = 0 ; i < N-1 ; i++)                                     \
    {                                                                   \
        EXPECT_LE(sorted_data[i], sorted_data[i+1]);                    \
    }                                                                   \
                                                                        \
    ASSERT_TRUE(VerifyIfAllNotNaN(sorted_data, N));                     \
    ASSERT_TRUE(VerifyIfOrdered(sorted_data, N));                       \
    ASSERT_TRUE(VerifySortedUnique(to_sort_data, sorted_data, N));      \
}

#define SORT_AND_VERIFY(to_sort_data, sorted_data, N, SortingFunction, verbose) \
{                                                                       \
    sorting::efficient::MergeSort(sorted_data, N);                      \
                                                                        \
    if (verbose)                                                        \
    {                                                                   \
        std::cout << "Arrays" << std::endl;                             \
        std::cout << "Index Original     Sorted " << std::endl;         \
        for (int i = 0 ; i < N ; i++)                                   \
        {                                                               \
            std::cout << i+1 << "/" << N << "   "                       \
                        << to_sort_data[i] << "        "                \
                        << sorted_data[i] << std::endl;                 \
        }                                                               \
    }                                                                   \
                                                                        \
    VALIDATE_SORTING(to_sort_data, sorted_data, N);                     \
}

#endif  // SORTING_UNIT_TESTS_VERIFYSORTEDARRAYS_H_
