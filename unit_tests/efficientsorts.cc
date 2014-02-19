#include "gtest/gtest.h"

#include "sorting.h"
#include "verifysortedarrays.h"

// *********************************************************************
TEST(EfficientSorts, MergeSortMultipleSizes)
{
    const double to_sorts[] = {6.0,   5.0,  3.0,  1.0,  2.4, 4.0, 10.0, 7.0,
                               3.42, 32.2, 44.2, 56.3, 67.9, 3.2, 44.2, 2.0};

    VERIFY_SORTING_FIXED_SIZE_ARRAYS(16, to_sorts, sorting::efficient::MergeSort, false);
}

// *********************************************************************
TEST(EfficientSorts, MergeSortMultipleSizesRandom)
{
    VERIFY_SORTING_RANDOM_ARRAYS(100, sorting::efficient::MergeSort, false)
}
