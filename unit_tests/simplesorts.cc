#include <iostream>   // std::cout

#include "gtest/gtest.h"

#include "simplesorts.h"
#include "printarray.h"

//#define quiet

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

    delete[] to_sort_data;
    delete[] sorted_data;
}
