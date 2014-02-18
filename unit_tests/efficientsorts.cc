#include <iostream>     // std::cout
#include <stdlib.h>     // rand()
#include <time.h>       // time()

#include "gtest/gtest.h"

#include "sorting.h"
#include "printarray.h"
#include "verifyarrays.h"

#define quiet

// *********************************************************************
TEST(EfficientSorts, MergeSortRecursive)
{
    const int N = 4;

    double *to_sort_data = new double[N];
    double *sorted_data  = new double[N];

    // Initialize the array with random values between 1 and 100
    // NOTE: rand() is a terrible pseudo-random number generator (PRNG).
    // It is still used here for a simple testing task, but don't use it
    // for anything serious.
    srand(time(NULL));
    for (int i = 0 ; i < N ; i++)
    {
        to_sort_data[i] = rand() % 100 + 1;
    }
    to_sort_data[0] = 6.0;
    to_sort_data[1] = 5.0;
    to_sort_data[2] = 3.0;
    to_sort_data[3] = 1.0;

    memcpy(sorted_data, to_sort_data, N*sizeof(double));

    sorting::efficient::MergeSortRecursive(sorted_data, N);

#ifndef quiet
    std::cout << "Arrays" << std::endl;
    std::cout << "Index Original     Sorted " << std::endl;
    for (int i = 0 ; i < N ; i++)
    {
        std::cout << i+1 << "/" << N << "   "
                    << to_sort_data[i] << "        "
                    << sorted_data[i] << std::endl;
    }
#endif // quiet

    for (int i = 1 ; i < N ; i++)
    {
        EXPECT_GE(sorted_data[i], sorted_data[i-1]);
    }

    for (int i = 0 ; i < N ; i++)
    {
        EXPECT_NE(sorted_data[i], 0);
    }
    ASSERT_TRUE(VerifyIfAllNotNaN(sorted_data, N));
    ASSERT_TRUE(VerifyIfOrdered(sorted_data, N));
    ASSERT_TRUE(VerifySortedUnique(to_sort_data, sorted_data, N));

    delete[] to_sort_data;
    delete[] sorted_data;
}
