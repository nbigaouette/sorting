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
    if (N == 1)
    {
        return;
    }

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
            //for (int i = sai*level_size ; i < (sai+2)*level_size-(N%2) ; i++)
            for (int i = sai*level_size ; i < std::min((sai+2)*level_size, N) ; i++)
            {
                // Take the element from the left subarray or from the right one?)
                bool take_left;

                // All subelements of the left subarray are exhausted. Use the left array value.
                if (li == (sai+1)*level_size)           take_left = false;
                // All subelements of the right subarray are exhausted. Use the right array value.
                else if (ri == (sai+2)*level_size)      take_left = true;
                // The right subarray is empty
                else if (ri >= N)                       take_left = true;
                // The left subarray is empty
                else if (li >= (sai+1)*level_size)      take_left = false;
                // Compare elements
                else if (to_sort[li] <= to_sort[ri])    take_left = true;
                else /*  to_sort[li] >  to_sort[ri] */  take_left = false;

                if (take_left)
                {
                    new_array[i] = to_sort[li];
                    li++;
                }
                else
                {
                    new_array[i] = to_sort[ri];
                    ri++;
                }

            }
        }

        level_i++;
        level_size *= 2;
    }

    // Copy the temporary array back to the original one if it was the last
    // one to be updated.
    if ((level_i % 2) != 0)
    {
        memcpy(array, tmp_array, N*sizeof(T));
    }
    delete[] tmp_array;
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
        MergeSortRecursive(array,             N_half_left);
        MergeSortRecursive(array+N_half_left, N_half_right);

        T *tmp_array   = new T[N];
        int li = 0;
        int ri = N_half_left;
        for (int i = 0 ; i < N ; i++)
        {
            bool take_left;
            if      (li >= N_half_left)         take_left = false;
            else if (ri >= N)                   take_left = true;
            else if (array[li] <= array[ri])    take_left = true;
            else /* (array[li] >  array[ri])*/  take_left = false;

            if (take_left) tmp_array[i] = array[li];
            else           tmp_array[i] = array[ri];
        }
        memccpy(array, tmp_array, N*sizeof(T));
        delete[] tmp_array;
    }
}

} // namespace efficient
} // namespace sorting

#endif  // SORTING_INCLUDE_EFFICIENTSORTS_MERGE_INL_H_
