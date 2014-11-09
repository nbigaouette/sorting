#ifndef SORTING_INCLUDE_PRINTARRAY_INL_H_
#define SORTING_INCLUDE_PRINTARRAY_INL_H_

#include <iomanip>
#include <iostream>


template <class T>
void PrintArray(T * const array, const int N)
{
    std::cout << "N = " << N << std::endl;
    for (int i = 0 ; i < N ; i++)
    {
        std::cout << std::setw(3) << array[i] << " ";
    }
    std::cout << std::endl;
}

#endif  // SORTING_INCLUDE_PRINTARRAY_INL_H_
