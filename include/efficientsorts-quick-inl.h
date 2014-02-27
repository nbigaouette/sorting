#ifndef SORTING_INCLUDE_EFFICIENTSORTS_QUICK_INL_H_
#define SORTING_INCLUDE_EFFICIENTSORTS_QUICK_INL_H_

namespace sorting {
namespace efficient {

template <class T>
void Quicksort(T * const array, const int N)
{
    if (N <= 1)
    {
        return;
    }
    else if (N == 2)
    {
        if (array[0] > array[1])
        {
            std::swap(array[0], array[1]);
        }
        return;
    }

    int pivot = N-1;
    int i0 = 0;
    int i1 = pivot-1;
    while (true)
    {
        const int prev_i0 = i0;
        const int prev_i1 = i1;
        i0 = -1;
        i1 = -1;

        // Find the first element that is larger than the pivot
        for (int i = prev_i0 ; i < pivot ; i++)
        {
            if (array[i] > array[pivot])
            {
                i0 = i;
                break;
            }
        }

        // Find the last element that is smaller than the pivot
        for (int i = prev_i1 ; i > i0 ; i--)
        {
            if (array[i] < array[pivot])
            {
                i1 = i;
                break;
            }
        }

        if (i0 == -1 and i1 == -1)
        {
            // If both i0 and i1 are -1, no every elements are not larger or not smaller
            // than the pivot; the whole array is equal. In that case, we return.
            return;
        }
        else if (i0 == -1)
        {
            // All elements are either smaller or equal to the pivot
            // Keep the pivot at the end of the array.
            i0 = N-1;
            i1 = N;
            break;
        }
        else if (i1 == -1)
        {
            // All elements are either larger or equal to the pivot
            // Place pivot at the beginning.
            i1 = i0 + 1;
            break;
        }
        else
        {
            // Swap elements i0 and i1
            std::swap(array[i0], array[i1]);
            i0++;
            i1--;
        }
    }

    // Swap the pivot with the first element of the large values
    if (i0 != pivot)
    {
        std::swap(array[i0], array[pivot]);
    }

    // Recursively call function on the two subarrays
    Quicksort(array, i0);
    Quicksort(array+i0+1, N-i1);
}

} // namespace efficient
} // namespace sorting

#endif // #ifndef SORTING_INCLUDE_EFFICIENTSORTS_QUICK_INL_H_
