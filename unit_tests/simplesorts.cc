#include <stdlib.h> // rand()
#include <time.h>   // time()
#include <iostream>   // std::cout

#include "gtest/gtest.h"

#include "simplesorts.h"

TEST(SimpleSorts, InsertionSort)
{
    const int N = 4;

    double *random_data = new double[N];
    double *sorted_data = new double[N];
    memset(sorted_data, 0, N*sizeof(double));

    // Populate array with random data between 1 and 100
    // Note that rand() is a BAD pseudo-random number generator (PRNG).
    // Don't use it for anything serious!
    srand(time(NULL));
    for (int i = 0 ; i < N ; i++)
    {
        random_data[i] = rand() % 100 + 1;
    }

    /*
    std::cout << "random_data:" << std::endl;
    for (int i = 0 ; i < N ; i++)
    {
        std::cout << i << "/" << N << "   " << random_data[i] << std::endl;
    }
    */

  //  InsertionSort(random_data, sorted_data, N);

//    /*
    std::cout << "sorted_data:" << std::endl;
    for (int i = 0 ; i < N ; i++)
    {
        std::cout << i << "/" << N << "   " << sorted_data[i] << std::endl;
    }
//    */

    for (int i = 1 ; i < N ; i++)
    {
        EXPECT_GE(sorted_data[i], sorted_data[i-1]);
    }

    for (int i = 0 ; i < N ; i++)
    {
        EXPECT_NE(sorted_data[i], 0);
    }

    delete[] random_data;
    delete[] sorted_data;
}
