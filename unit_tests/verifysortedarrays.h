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
    SortingFunction(sorted_data, N);                                    \
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

#define VERIFY_SORTING_INPLACE_RANDOM_ARRAYS(Nmax, type, SortingFunction, verbose) \
{                                                                       \
    for (int N = 1 ; N < Nmax ; N++)                                    \
    {                                                                   \
        type *to_sort_data = new type[N];                               \
        type *sorted_data  = new type[N];                               \
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
        memcpy(sorted_data, to_sort_data, N*sizeof(type));              \
                                                                        \
        SORT_AND_VERIFY(to_sort_data, sorted_data, N, SortingFunction, verbose); \
                                                                        \
        delete[] to_sort_data;                                          \
        delete[] sorted_data;                                           \
    }                                                                   \
}

#define VERIFY_SORTING_INPLACE_FIXED_SIZE_ARRAYS(Nmax, type, to_sorts, SortingFunction, verbose) \
{                                                                       \
    for (int N = 1 ; N <= Nmax ; N++)                                   \
    {                                                                   \
        type *to_sort_data = new type[N];                               \
        type *sorted_data  = new type[N];                               \
                                                                        \
        for (int i = 0 ; i < N ; i++)                                   \
        {                                                               \
            to_sort_data[i] = to_sorts[i];                              \
        }                                                               \
                                                                        \
        memcpy(sorted_data, to_sort_data, N*sizeof(type));              \
                                                                        \
        SORT_AND_VERIFY(to_sort_data, sorted_data, N, SortingFunction, verbose); \
                                                                        \
        delete[] to_sort_data;                                          \
        delete[] sorted_data;                                           \
    }                                                                   \
}

#define VERIFY_SORTING_INPLACE_FIXED_SIZE_ARRAYS_AND_COMPARE(N, type, to_sort, known_sorted, SortingFunction, verbose) \
{                                                                       \
    type *to_sort_data = new type[N];                                   \
    type *sorted_data  = new type[N];                                   \
                                                                        \
    for (int i = 0 ; i < N ; i++)                                       \
    {                                                                   \
        to_sort_data[i] = to_sort[i];                                   \
    }                                                                   \
                                                                        \
    memcpy(sorted_data, to_sort_data, N*sizeof(type));                  \
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

#define VERIFY_SORTING_INPLACE_SORTED_ARRAY(Nmax, type, SortingFunction, verbose) \
{                                                                       \
    for (int N = 1 ; N < Nmax ; N++)                                    \
    {                                                                   \
        type *to_sort_data = new type[N];                               \
        type *sorted_data  = new type[N];                               \
                                                                        \
        for (int i = 0 ; i < N ; i++)                                   \
        {                                                               \
            to_sort_data[i] = i;                                        \
        }                                                               \
                                                                        \
        memcpy(sorted_data, to_sort_data, N*sizeof(type));              \
                                                                        \
        SORT_AND_VERIFY(to_sort_data, sorted_data, N, SortingFunction, verbose); \
                                                                        \
        delete[] to_sort_data;                                          \
        delete[] sorted_data;                                           \
    }                                                                   \
}

#define VERIFY_SORTING_INPLACE_INV_SORTED_ARRAY(Nmax, type, SortingFunction, verbose) \
{                                                                       \
    for (int N = 1 ; N < Nmax ; N++)                                    \
    {                                                                   \
        type *to_sort_data = new type[N];                               \
        type *sorted_data  = new type[N];                               \
                                                                        \
        for (int i = 0 ; i < N ; i++)                                   \
        {                                                               \
            to_sort_data[i] = N-i;                                      \
        }                                                               \
                                                                        \
        memcpy(sorted_data, to_sort_data, N*sizeof(type));              \
                                                                        \
        SORT_AND_VERIFY(to_sort_data, sorted_data, N, SortingFunction, verbose); \
                                                                        \
        delete[] to_sort_data;                                          \
        delete[] sorted_data;                                           \
    }                                                                   \
}

#endif  // SORTING_UNIT_TESTS_VERIFYSORTEDARRAYS_H_
