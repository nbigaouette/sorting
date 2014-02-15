#include <stdlib.h> // rand()
#include <time.h>   // time()
#include <iostream>   // std::cout

#include "gtest/gtest.h"

#include "simplesorts.h"

TEST(SimpleSorts, InsertionSort)
{
    const int N = 10;

    double *random_data = new double[N];
    double *sorted_data = new double[N];

    // Populate array with random data.
    // Note that rand() is a BAD pseudo-random number generator (PRNG).
    // Don't use it for anything serious!
    srand(time(NULL));
    for (int i = 0 ; i < N ; i++)
    {
        random_data[i] = rand() % 100;
    }

    std::cout << "random_data:" << std::endl;
    for (int i = 0 ; i < N ; i++)
    {
        std::cout << i << "/" << N << "   " << random_data[i] << std::endl;
    }

    InsertionSort(random_data, sorted_data, N);

    std::cout << "random_data:" << std::endl;
    for (int i = 0 ; i < N ; i++)
    {
        std::cout << i << "/" << N << "   " << random_data[i] << std::endl;
    }

    delete[] random_data;
    delete[] sorted_data;
}
