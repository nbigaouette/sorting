#ifndef SORTING_INCLUDE_SIMPLESORTS_INSERTION_INL_H_
#define SORTING_INCLUDE_SIMPLESORTS_INSERTION_INL_H_

namespace sorting {
namespace simple {

template <class T>
void InsertionSort(T * const array, const int N)
/**
 * Simple sorts: Insertion sort
 * Scaling:
 *      Best case:  O(N)        When array is already sorted
 *      Worst case: O(N^2)      When array is sorted in reverse order
 * Useful:
 *      In place
 *      Good when array is small
 */
{
    // Return if array size is 1 or less
    if (N <= 1)
    {
        return;
    }

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

            // Go back in the array, starting with previous value.
            int j;
            for (j = i-1 ; j >= 0 ; j--)
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
                }
            }
            // If the loop index "j" is -1, the previous loop ended without hitting
            // the break statement, meaning we hit the start of the array. In that
            // case, place the stored element there.
            if (j == -1)
            {
                array[0] = tmp;
            }
        }
    }
}

} // namespace simple
} // namespace sorting

#endif  // SORTING_INCLUDE_SIMPLESORTS_INSERTION_INL_H_
