#ifndef SORTING_INCLUDE_SIMPLESORTS_SELECTION_INL_H_
#define SORTING_INCLUDE_SIMPLESORTS_SELECTION_INL_H_

namespace simplesorts {

template <class T>
void SelectionSort(T * const array, const int N)
/**
 * Simple sorts: Selection sort
 * Scaling:
 *      Best case:  O(N^2) (note the nested loop)
 *      Worst case: Same
 * Useful:
 *      When swapping is expensive, as there is maximum of N swaps.
 */
{
    // Loop over all elements
    for (int i = 0 ; i < N ; i++)
    {
        int smallest_j   = i;
        T   smallest_val = array[i];
        // Loop over all remaining elements and find the smallest value
        for (int j = i+1 ; j < N ; j++)
        {
            if (array[j] < smallest_val)
            {
                smallest_j   = j;
                smallest_val = array[j];
            }
        }
        // Once the smallest value in the rest of the array is found,
        // swap it with the current value.
        std::swap(array[i], array[smallest_j]);
    }
}

} // namespace simplesorts

#endif  // SORTING_INCLUDE_SIMPLESORTS_SELECTION_INL_H_
