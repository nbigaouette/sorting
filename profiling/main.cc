#include <iostream>
#include "sorting.h"
#include "printarray.h"

#include <vector>
#include <cmath>
#include <random>
#include <functional>
#include <chrono>


double profileAverage_ms(const int *const data, const int N, const int avgN, void (*sort)(int * const, const int))
{
    int *array = new int[N];

    std::vector<double> diffs(avgN);
    //double avg = 0.0;

    for (int j = 0 ; j < avgN ; j++)
    {
        memcpy(array, data+j, N*sizeof(int));

        //PrintArray(array, N);

        auto start = std::chrono::steady_clock::now();
        (*sort)(array, N);
        auto stop  = std::chrono::steady_clock::now();

        //PrintArray(array, N);

        auto diff = stop - start;
        diffs[j] = std::chrono::duration <double, std::milli> (diff).count();
    }

    double avg = 0.0;
    for (int j = 0 ; j < avgN ; j++)
    {
        avg += diffs[j] / double(avgN);
    }
    double stddev = 0.0;
    for (int j = 0 ; j < avgN ; j++)
    {
        stddev += (diffs[j] - avg)*(diffs[j] - avg) / double(avgN);
    }
    stddev = std::sqrt(stddev);

    std::cout << N << ", " << avg << " +- " << stddev << " ms" << std::endl;

    delete[] array;

    return avg;
}


void profileSort(void (*sort)(int * const, const int))
{
    const int pow2min = 0;
    const int pow2max = 16;

    const int seed = 4;

    std::uniform_int_distribution<int> distribution(0, 99);
    std::mt19937 engine(seed); // Mersenne twister MT19937
    auto generator = std::bind(distribution, engine);


    // Allocate more than required; profileAverage() will copy the data
    // with an offset.
    int *data = new int[2 << (pow2max+1)];
    for (int i = 0 ; i < 2 << (pow2max+1) ; i++)
    {
        data[i] = generator();
    }


    //PrintArray(Ns.data(), Ns.size());

    for (int j = pow2min ; j <= pow2max ; j++)
    {
        const int N = 2 << j;
        profileAverage_ms(data, N, 6, sort);
        //std::cout << j << ", " << N << ", " << profileAverage_ms(data, N, 6, sort) << " ms" << std::endl;
    }

    delete[] data;
}

void generate_profiling_data()
{
    //profileSort(&sorting::simple::InsertionSort);
    profileSort(&sorting::efficient::Quicksort);
}

int main(int argc, char *argv[])
{
    std::cout << "main()" << std::endl;

    generate_profiling_data();
}
