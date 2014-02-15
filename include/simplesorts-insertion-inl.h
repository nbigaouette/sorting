#ifndef SORTING_INCLUDE_SIMPLESORT_INSERTION_INL_H_
#define SORTING_INCLUDE_SIMPLESORT_INSERTION_INL_H_

#include <cmath>

template <class T>
void InsertionSort(T * const array, const int N)
{
    // Temporary value used during sorting
    T tmp;

    // Loop over all other elements
    for (int i = 1 ; i < N ; i++)
    {

        // If the current element is smaller than the previous one, we
        // go back in the array until we find the right place for the element.
        if (array[i-1] > array[i])
        {
            // Temporarely store the element to sort
            tmp = array[i];
            array[i] = NAN;

            // Go back in the array, starting with previous value.
            for (int j = i-1 ; j >= 0 ; j--)
            {
                // If stored value is larger than array value, place stored value after
                if (tmp >= array[j])
                {
                    array[j+1] = tmp;
                    break;
                }
                else
                {
                    // Move element up
                    array[j+1] = array[j];
                    array[j] = NAN;
                }
            }
            // If the first element is NaN, then the previous loop ended without
            // finding a smaller number than the one stored. In that case, it is
            // the smallest! Place it at the begining.
            if (isnan(array[0]))
            {
                array[0] = tmp;
            }
        }
    }
}

#endif  // SORTING_INCLUDE_SIMPLESORT_INSERTION_INL_H_
