#include "gtest/gtest.h"

#include "sorting.h"
#include "verifysortedarrays.h"

// *********************************************************************
TEST(EfficientSorts, MergeSortMultipleSizes)
{
    const double to_sorts[] = {6.0,   5.0,  3.0,  1.0,  2.4, 4.0, 10.0, 7.0,
                               3.42, 32.2, 44.2, 56.3, 67.9, 3.2, 44.2, 2.0};

    for (int N = 1 ; N <= 16 ; N++)
    {
        double *to_sort_data = new double[N];
        double *sorted_data  = new double[N];

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
    VERIFY_SORTING_RANDOM_ARRAYS(100, sorting::efficient::MergeSort, false)
}
