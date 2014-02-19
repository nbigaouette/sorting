#include <iostream>     // std::cout
#include <stdlib.h>     // rand()
#include <time.h>       // time()

#include "gtest/gtest.h"

#include "sorting.h"
#include "printarray.h"
#include "verifyarrays.h"
#include "verifysortedarrays.h"

#define quiet

// *********************************************************************
TEST(EfficientSorts, MergeSortMultipleSizes)
{
    const double to_sorts[] = {6.0, 5.0, 3.0, 1.0, 2.4, 4.0, 10.0, 7.0};

    for (int N = 1 ; N < 8 ; N++)
    {
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
        for (int i = 0 ; i < N ; i++)
        {
            to_sort_data[i] = to_sorts[i];
        }

        memcpy(sorted_data, to_sort_data, N*sizeof(double));

        SORT_AND_VERIFY(to_sort_data, sorted_data, N, sorting::efficient::MergeSort, false);

        delete[] to_sort_data;
        delete[] sorted_data;
    }
}

// *********************************************************************
TEST(EfficientSorts, MergeSortMultipleSizesRandom)
{
    for (int N = 1 ; N < 100 ; N++)
    {
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

        memcpy(sorted_data, to_sort_data, N*sizeof(double));

        SORT_AND_VERIFY(to_sort_data, sorted_data, N, sorting::efficient::MergeSort, false);

        delete[] to_sort_data;
        delete[] sorted_data;
    }
}
