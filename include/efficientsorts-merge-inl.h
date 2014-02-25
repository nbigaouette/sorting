#ifndef SORTING_INCLUDE_EFFICIENTSORTS_MERGE_INL_H_
#define SORTING_INCLUDE_EFFICIENTSORTS_MERGE_INL_H_

#include <cstring> // memmove()

namespace sorting {
namespace efficient {

template <class T>
void MergeSort(T * const array, const int N)
/**
 * Efficient sorts: Merge sort (non-recursive)
 * Scaling:
 *      Best case:  O(N log N)
 *      Worst case: O(N log N)
 * Useful:
 * Note:
 *      An extra array is allocated, so this is not optimal for really
 *      large arrays.
 */
{
    if (N == 1)
    {
        return;
    }

    // Divide the array into sub-arrays of size "level_size".
    int level_size = 1;
    int level_i    = 0; // Index of level
    while (level_size < N)
    {
        // Number of subarrays in current level
        // If "N" is divisible by the "level_size", the modulo is null and
        // the ratio gives the number of subarrays.
        // If "N" is not divisible by the "level_size", the modulo is not null.
        // In that case, there is a remainder to the division so we add 1 which
        // whill contian the rest.
        const int Ns = ((N % level_size) == 0) ? N/level_size : N/level_size+1;

        // "sai" == Sub Array (starting) Index
        for (int sai = 0 ; sai < Ns ; sai += 2)
        {
            const int N_half_left  = std::max(0, std::min(N, (sai+1)*level_size) - (sai  )*level_size);
            const int N_half_right = std::max(0, std::min(N, (sai+2)*level_size) - (sai+1)*level_size);

            int li =  sai   *level_size;    // Left subarray's starting index of global array
            int ri = (sai+1)*level_size;    // Right subarray's starting index of global array

            // Loop over the subarray's elements
            const int i0 = sai*level_size;
            const int iN = i0+N_half_left+N_half_right;
            for (int i = i0 ; i < iN-1 and li<ri ; i++)
            {
                assert(li >= i0);
                assert(ri >= i0);
                assert(li <  iN);

                if (li == ri or ri >= iN)
                {
                    // Exhausted one of the two sub-array. The other one is already
                    // in place, so nothing left has to be done and break the loop.
                    break;
                }
                else if (array[li] <= array[ri])
                {
                    // Do nothing as left element is already in place
                    li++;
                }
                else
                {
                    // Take the right element.
                    // Copy right element into a temporary buffer, then move all elements
                    // between the current location "i" and the right element "ri" one to the right
                    T tmp_element = array[ri];
                    memmove(array+i+1, array+i, (ri-i)*sizeof(T));
                    array[i] = tmp_element;
                    // li has moved, increment it
                    li++;
                    // ri was moved, go to next
                    ri++;
                }
            }
        }

        level_i++;
        level_size *= 2;
    }
}

template <class T>
void MergeSortRecursive(T * const array, const int N)
/**
 * Efficient sorts: Merge sort (recursive)
 * Scaling:
 *      Best case:  O(N log N)
 *      Worst case: O(N log N)
 * Useful:
 * Note:
 *      An extra array is allocated, so this is not optimal for really
 *      large arrays.
 */
{
    if (N == 1)
    {
        return;
    }
    else
    {
        const int N_half_left  = (N / 2) + (N % 2);
        const int N_half_right = N - N_half_left;

        MergeSortRecursive(array, N_half_left);
        MergeSortRecursive(array+N_half_left, N_half_right);

        int li = 0;             // Index of left element
        int ri  = N_half_left;  // Index of right element
        int i = -1;
        while (li < ri and ri < N)
        {
            i++;

            if (array[li] <= array[ri])
            {
                // Do nothing as left element is already in place
                li++;
            }
            else
            {
                // Copy right element into a temporary buffer, then move all elements
                // between the current location "i" and the right element "ri" one to the right
                T tmp_element = array[ri];
                memmove(array+i+1, array+i, (ri-i)*sizeof(T));
                array[i] = tmp_element;
                // li has moved, increment it
                li++;
                // ri was moved, go to next
                ri++;
            }
        }
    }
}

} // namespace efficient
} // namespace sorting

#endif  // SORTING_INCLUDE_EFFICIENTSORTS_MERGE_INL_H_
