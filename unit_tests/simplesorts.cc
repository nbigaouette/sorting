#include <iostream>   // std::cout

#include "gtest/gtest.h"

#include "simplesorts.h"
#include "printarray.h"

#define quiet

bool VerifyIfAllNotNaN(double const * const sorted, const int N)
{
    // Verify any NaN
    for (int i = 1 ; i < N ; i++)
    {
        if (isnan(sorted[i]))
        {
            return false;
        }
    }
    return true;
}

bool VerifyIfOrdered(double const * const sorted, const int N)
{
    // Make sure array is ordered
    for (int i = 1 ; i < N ; i++)
    {
        if (sorted[i] <= sorted[i-1])
        {
            return false;
        }
    }
    return true;
}

bool VerifySortedUnique(double const * const original, double const * const sorted, const int N)
{
    // Make sure every element of the original array is present in the sorted one
    // Make a temporary copy of the arrays
    double *tmp_orig = new double[N];
    double *tmp_sort = new double[N];
    memcpy(tmp_orig, original, N*sizeof(double));
    memcpy(tmp_sort, sorted,   N*sizeof(double));
    // Flag every element of the (copied) arrays that match.
    for (int i = 0 ; i < N ; i++)
    {
        for (int j = 0 ; j < N ; j++)
        {
            // Note that NAN != NAN
            if (tmp_orig[i] == tmp_sort[j])
            {
                tmp_orig[i] = NAN;
                tmp_sort[j] = NAN;
                break;
            }
        }
    }
    // Now verify if one element of the temporary arrays is _not_ NaN.
    // In that case, something went wrong!
    for (int i = 0 ; i < N ; i++)
    {
        if (not isnan(tmp_orig[i]))
        {
            return false;
        }
        if (not isnan(tmp_sort[i]))
        {
            return false;
        }
    }
    delete[] tmp_orig;
    delete[] tmp_sort;

    return true;
}

TEST(SimpleSorts, InsertionSort)
{
    const int N = 5;

    double *to_sort_data = new double[N];
    double *sorted_data  = new double[N];

    to_sort_data[0] = 21.3;
    to_sort_data[1] = 68.2;
    to_sort_data[2] = 1.3;
    to_sort_data[3] = 44.3;
    to_sort_data[4] = 10.3;

    for (int i = 0 ; i < N ; i++)
    {
        sorted_data[i] = to_sort_data[i];
    }

    InsertionSort(sorted_data, N);

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
