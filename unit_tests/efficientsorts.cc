#include "gtest/gtest.h"

#include "sorting.h"
#include "verifysortedarrays.h"

// *********************************************************************
TEST(EfficientSorts, MergeSortMultipleSizesDouble)
{
    const double to_sorts[] = {6.0,   5.0,  3.0,  1.0,  2.4, 4.0, 10.0, 7.0,
                               3.42, 32.2, 44.2, 56.3, 67.9, 3.2, 44.2, 2.0};

    VERIFY_SORTING_FIXED_SIZE_ARRAYS(16, double, to_sorts, sorting::efficient::MergeSort, false);
}

// *********************************************************************
TEST(EfficientSorts, MergeSortKnownResultDouble)
{
    const double to_sorts[] = {6.0,   5.0,  3.0,  1.0,  2.4, 4.0, 10.0, 7.0,
                               3.42, 32.2, 44.2, 56.3, 67.9, 3.2, 44.2, 2.0};
    const double known_sorted[] = { 1.0, 2.0,  2.4,  3.0,  3.2,  3.42,  4.0,  5.0,
                                    6.0, 7.0, 10.0, 32.2, 44.2, 44.2,  56.3, 67.9};

    VERIFY_SORTING_FIXED_SIZE_ARRAYS_AND_COMPARE(16, double, to_sorts, known_sorted, sorting::efficient::MergeSort, false);
}

// *********************************************************************
TEST(EfficientSorts, MergeSortMultipleSizesRandomDouble)
{
    VERIFY_SORTING_RANDOM_ARRAYS(100, double, sorting::efficient::MergeSort, false)
}
