#ifndef SORTING_INCLUDE_PRINTARRAY_INL_H_
#define SORTING_INCLUDE_PRINTARRAY_INL_H_

template <class T>
void PrintArray(T * const array, const int N)
{
    for (int i = 0 ; i < N ; i++)
    {
        std::cout << i << "/" << N << "   " << array[i] << std::endl;
    }
}

#endif  // SORTING_INCLUDE_PRINTARRAY_INL_H_
