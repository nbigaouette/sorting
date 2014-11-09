#include <iostream>
#include "sorting.h"
#include "printarray.h"

#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <functional>
#include <chrono>
#include <fstream>


std::vector<double> profileAverage_ms(const int *const data, const int N, const int avgN, void (*sort)(int * const, const int))
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

    delete[] array;

    std::vector<double> timing_ms = {avg, stddev};

    return timing_ms;
}


void profileSort(const std::string sort_name, void (*sort)(int * const, const int))
{
    const int pow2min = 0;
    const int pow2max = 9;

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

    const std::string output_filename = "profiling_" + sort_name + ".csv";

    std::cout << "Profiling " << sort_name << " (saving to " << output_filename << ")" << std::endl;

    std::ofstream output_file;
    output_file.open(output_filename);

    output_file << "# 2^j, N, avg [ms], stddev [ms]" << std::endl;

    for (int j = pow2min ; j <= pow2max ; j++)
    {
        const int N = 2 << j;
        auto timing_ms = profileAverage_ms(data, N, 6, sort);
        output_file << j << ", " << N << ", " << timing_ms[0] << ", " << timing_ms[1] << std::endl;
        std::cout << N << ": " << timing_ms[0] << " +- " << timing_ms[1] << " ms" << std::endl;
    }

    output_file.close();

    delete[] data;
}

void generate_profiling_data()
{
    profileSort("simple_insertionsort",             &sorting::simple::InsertionSort);
    profileSort("simple_selectionsort",             &sorting::simple::SelectionSort);
    profileSort("efficient_mergesort",              &sorting::efficient::MergeSort);
    profileSort("efficient_mergesort_recursive",    &sorting::efficient::MergeSortRecursive);
    profileSort("efficient_quicksort",              &sorting::efficient::Quicksort);
    profileSort("bubble_bubblesort",                &sorting::bubble::BubbleSort);
    profileSort("bubble_bubblesortoptimized",       &sorting::bubble::BubbleSortOptimized);
    profileSort("bubble_bubblesortoptimized2",      &sorting::bubble::BubbleSortOptimized2);
}

int main(int argc, char *argv[])
{
    generate_profiling_data();
}
