#ifndef SORTING_INCLUDE_EFFICIENTSORTS_MERGE_INL_H_
#define SORTING_INCLUDE_EFFICIENTSORTS_MERGE_INL_H_

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
    PrintArray(array, N);

    T *tmp_array = new T[N];

    // Pointers to begining of each arrays, pointing to the original array
    // and the temporary array interchangely.
    T * arrays[2] = {tmp_array, array};

    // Divide the array into sub-arrays of size "level_size"
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

        // Alternate between the two arrays
        T *new_array = arrays[ level_i      % 2];
        T *to_sort   = arrays[(level_i + 1) % 2];

        // "sai" == Sub Array (starting) Index
        for (int sai = 0 ; sai < Ns ; sai += 2)
        {
            int li =  sai   *level_size;    // Left subarray's starting index of global array
            int ri = (sai+1)*level_size;    // Right subarray's starting index of global array

            // Loop over the subarray's elements
            for (int i = sai*level_size ; i < (sai+2)*level_size ; i++)
            {
                if (li == (sai+1)*level_size)
                {
                    // All subelements of the left subarray are exhausted. Use the left array value.
                    new_array[i] = to_sort[ri];
                    ri++;
                }
                else if (ri == (sai+2)*level_size)
                {
                    // All subelements of the right subarray are exhausted. Use the right array value.
                    new_array[i] = to_sort[li];
                    li++;
                }
                else if (to_sort[li] <= to_sort[ri])
                {
                    // Use "<=" for stability
                    new_array[i] = to_sort[li];
                    li++;
                }
                else
                {
                    new_array[i] = to_sort[ri];
                    ri++;
                }
                assert(li <= N+1);
                assert(ri <= N+1);
            }
        }

        level_i++;
        level_size *= 2;
    }
    delete[] tmp_array;
}

} // namespace efficient
} // namespace sorting

#endif  // SORTING_INCLUDE_EFFICIENTSORTS_MERGE_INL_H_
