#ifndef SORTING_INCLUDE_BUBBLESORTS_BUBBLE_INL_H_
#define SORTING_INCLUDE_BUBBLESORTS_BUBBLE_INL_H_

namespace sorting {
namespace bubble {

template <class T>
void BubbleSort(T * const array, const int N)
/**
 * Bubble sort: Bubble sort
 * Scaling:
 *      Best case:      O(N)
 *      Worst case:     O(N^2)
 * Useful:
 *      Almost none; really slow, but extremely easy to implement.
 */
{
    int pass_count = 0;  // Number of pass over the array.
    int swap_count = 0;  // Number of swap for a single pass.

    // Pass over the array while the swap count is non-null.
    do
    {
        // It's a new pass; reset the count of swap.
        swap_count = 0;
        // Iterate over the array, skipping the last item
        for (int i = 0 ; i < N-1 ; i++)
        {
            // Swap elements if next one is "smaller" and register the swap.
            if (array[i] > array[i+1])
            {
                std::swap(array[i], array[i+1]);
                swap_count++;
            }
        }
        pass_count++;

    } while (swap_count != 0);
}

template <class T>
void BubbleSortOptimized(T * const array, const int N)
/**
 * Bubble sort: Bubble sort
 * Scaling:
 *      Best case:      O(N)
 *      Worst case:     O(N^2)
 * Useful:
 *      Almost none; really slow, but extremely easy to implement.
 */
{
    int pass_count = 0;  // Number of pass over the array.
    int swap_count = 0;  // Number of swap for a single pass.

    int loop_N = N;

    // Pass over the array while the swap count is non-null.
    do
    {
        // It's a new pass; reset the count of swap.
        swap_count = 0;
        // Iterate over the array, skipping the last item
        for (int i = 0 ; i < loop_N-1 ; i++)
        {
            // Swap elements if next one is "smaller" and register the swap.
            if (array[i] > array[i+1])
            {
                std::swap(array[i], array[i+1]);
                swap_count++;
            }
        }
        pass_count++;

        // Optimization: After M pass, the Mth element is at its final position
        loop_N--;

    } while (swap_count != 0);
}

template <class T>
void BubbleSortOptimized2(T * const array, const int N)
/**
 * Bubble sort: Bubble sort
 * Scaling:
 *      Best case:      O(N)
 *      Worst case:     O(N^2)
 * Useful:
 *      Almost none; really slow, but extremely easy to implement.
 */
{
    int pass_count = 0;  // Number of pass over the array.
    int swap_i = -1;     // Index of last swapped element.

    int loop_N = N;  // Last element to check during a pass.

    // Pass over the array while the last swapped element is non-negative
    do
    {
        // It's a new pass; reset the swap index.
        swap_i = -1;
        // Iterate over the array, skipping the last item
        for (int i = 0 ; i < loop_N-1 ; i++)
        {
            // Swap elements if next one is "smaller" and register the swap.
            if (array[i] > array[i+1])
            {
                std::swap(array[i], array[i+1]);
                swap_i = i+1;
            }
        }
        pass_count++;

        // Optimization: After M pass, the Mth element is at its final position
        loop_N = swap_i;

    } while (swap_i != -1);
}

} // namespace bubble
} // namespace sorting

#endif // SORTING_INCLUDE_BUBBLESORTS_BUBBLE_INL_H_
