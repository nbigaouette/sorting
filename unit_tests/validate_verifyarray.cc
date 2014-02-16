#include <iostream>   // std::cout

#include "gtest/gtest.h"

#include "simplesorts.h"
#include "printarray.h"
#include "verifyarrays.h"

TEST(VerifyArray, VerifyIfAllNotNaN)
{
    const int N = 5;
    double *data = new double[N];

    data[0] = 21.3;
    data[1] = 68.2;
    data[2] = 1.3;
    data[3] = 44.3;
    data[4] = 10.3;

    ASSERT_TRUE(VerifyIfAllNotNaN(data, N));

    data[3] = NAN;

    ASSERT_FALSE(VerifyIfAllNotNaN(data, N));

    delete[] data;
}

TEST(VerifyArray, VerifyIfOrdered)
{
    const int N = 5;
    double *data = new double[N];

    data[0] = 1.3;
    data[1] = 10.3;
    data[2] = 21.3;
    data[3] = 44.3;
    data[4] = 68.2;

    ASSERT_TRUE(VerifyIfOrdered(data, N));

    data[0] = 21.3;
    data[1] = 68.2;
    data[2] = 1.3;
    data[3] = 44.3;
    data[4] = 10.3;

    ASSERT_FALSE(VerifyIfOrdered(data, N));

    delete[] data;
}

TEST(VerifyArray, VerifySortedUnique)
{
    const int N = 5;
    double *data   = new double[N];
    double *sorted = new double[N];

    data[0] = 1.3;
    data[1] = 10.3;
    data[2] = 21.3;
    data[3] = 44.3;
    data[4] = 68.2;

    sorted[0] = 1.3;
    sorted[1] = 10.3;
    sorted[2] = 21.3;
    sorted[3] = 44.3;
    sorted[4] = 68.2;

    ASSERT_TRUE(VerifySortedUnique(data, sorted, N));

    sorted[2] = 12345678.9;

    ASSERT_FALSE(VerifySortedUnique(data, sorted, N));

    delete[] data;
    delete[] sorted;
}

