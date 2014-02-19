#ifndef SORTING_UNIT_TESTS_VERIFYSORTEDARRAYS_H_
#define SORTING_UNIT_TESTS_VERIFYSORTEDARRAYS_H_

#include <stdlib.h>     // rand()
#include <time.h>       // time()

#include "gtest/gtest.h"

#include "verifyarrays.h"

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

#define VERIFY_SORTING_RANDOM_ARRAYS(Nmax, SortingFunction, verbose)    \
    for (int N = 1 ; N < Nmax ; N++)                                    \
    {                                                                   \
        double *to_sort_data = new double[N];                           \
        double *sorted_data  = new double[N];                           \
                                                                        \
        /*
        Initialize the array with random values between 1 and 100       \
        NOTE: rand() is a terrible pseudo-random number generator (PRNG). \
        It is still used here for a simple testing task, but don't use it \
        for anything serious.
        */                                                              \
        srand(time(NULL));                                              \
        for (int i = 0 ; i < N ; i++)                                   \
        {                                                               \
            to_sort_data[i] = rand() % 100 + 1;                         \
        }                                                               \
                                                                        \
        memcpy(sorted_data, to_sort_data, N*sizeof(double));            \
                                                                        \
        SORT_AND_VERIFY(to_sort_data, sorted_data, N, SortingFunction, verbose); \
                                                                        \
        delete[] to_sort_data;                                          \
        delete[] sorted_data;                                           \
    }

#define VERIFY_SORTING_FIXED_SIZE_ARRAYS(Nmax, to_sorts, SortingFunction, verbose) \
    for (int N = 1 ; N <= Nmax ; N++)                                   \
    {                                                                   \
        double *to_sort_data = new double[N];                           \
        double *sorted_data  = new double[N];                           \
                                                                        \
        for (int i = 0 ; i < N ; i++)                                   \
        {                                                               \
            to_sort_data[i] = to_sorts[i];                              \
        }                                                               \
                                                                        \
        memcpy(sorted_data, to_sort_data, N*sizeof(double));            \
                                                                        \
        SORT_AND_VERIFY(to_sort_data, sorted_data, N, SortingFunction, verbose); \
                                                                        \
        delete[] to_sort_data;                                          \
        delete[] sorted_data;                                           \
    }

#define VERIFY_SORTING_FIXED_SIZE_ARRAYS_AND_COMPARE(N, to_sort, known_sorted, SortingFunction, verbose) \
{                                                                   \
    double *to_sort_data = new double[N];                           \
    double *sorted_data  = new double[N];                           \
                                                                    \
    for (int i = 0 ; i < N ; i++)                                   \
    {                                                               \
        to_sort_data[i] = to_sort[i];                               \
    }                                                               \
                                                                    \
    memcpy(sorted_data, to_sort_data, N*sizeof(double));            \
                                                                    \
    SORT_AND_VERIFY(to_sort_data, sorted_data, N, SortingFunction, verbose); \
                                                                        \
    for (int i = 0 ; i < N ; i++)                                       \
    {                                                                   \
        ASSERT_EQ(sorted_data[i], known_sorted[i]);                     \
    }                                                                   \
                                                                        \
    delete[] to_sort_data;                                              \
    delete[] sorted_data;                                               \
}

#endif  // SORTING_UNIT_TESTS_VERIFYSORTEDARRAYS_H_
