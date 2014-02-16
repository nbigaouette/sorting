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

