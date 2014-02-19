#include <iostream>     // std::cout
#include <stdlib.h>     // rand()
#include <time.h>       // time()

#include "gtest/gtest.h"

#include "sorting.h"
#include "verifysortedarrays.h"

#define quiet


// *********************************************************************
TEST(SimpleSorts, InsertionSortMultipleSizesDouble)
{
    const double to_sorts[] = {6.0,   5.0,  3.0,  1.0,  2.4, 4.0, 10.0, 7.0,
                               3.42, 32.2, 44.2, 56.3, 67.9, 3.2, 44.2, 2.0};

    VERIFY_SORTING_INPLACE_FIXED_SIZE_ARRAYS(16, double, to_sorts, sorting::simple::InsertionSort, false);
}

// *********************************************************************
TEST(SimpleSorts, InsertionSortMultipleSizesInt)
{
    const double to_sorts[] = {6,  5,  3,  1,  2, 4, 10, 7,
                               3, 32, 44, 56, 67, 3, 44, 2};

    VERIFY_SORTING_INPLACE_FIXED_SIZE_ARRAYS(16, int, to_sorts, sorting::simple::InsertionSort, false);
}

// *********************************************************************
TEST(SimpleSorts, InsertionortKnownResultDouble)
{
    const double to_sorts[] = {6.0,   5.0,  3.0,  1.0,  2.4, 4.0, 10.0, 7.0,
                               3.42, 32.2, 44.2, 56.3, 67.9, 3.2, 44.2, 2.0};
    const double known_sorted[] = { 1.0, 2.0,  2.4,  3.0,  3.2,  3.42,  4.0,  5.0,
                                    6.0, 7.0, 10.0, 32.2, 44.2, 44.2,  56.3, 67.9};

    VERIFY_SORTING_INPLACE_FIXED_SIZE_ARRAYS_AND_COMPARE(16, double, to_sorts, known_sorted, sorting::simple::InsertionSort, false);
}

// *********************************************************************
TEST(SimpleSorts, InsertionSortKnownResultInt)
{
    const double to_sorts[] = {6,   5,  3,  1,  2, 4, 10, 7,
                               3, 32, 44, 56, 67, 3, 44, 2};
    const double known_sorted[] = { 1, 2,  2,  3,  3,  3,  4,  5,
                                    6, 7, 10, 32, 44, 44,  56, 67};

    VERIFY_SORTING_INPLACE_FIXED_SIZE_ARRAYS_AND_COMPARE(16, int, to_sorts, known_sorted, sorting::simple::InsertionSort, false);
}

// *********************************************************************
TEST(SimpleSorts, InsertionSortMultipleSizesRandomDouble)
{
    VERIFY_SORTING_INPLACE_RANDOM_ARRAYS(100, double, sorting::simple::InsertionSort, false)
}

// *********************************************************************
TEST(SimpleSorts, InsertionSortMultipleSizesRandomInt)
{
    VERIFY_SORTING_INPLACE_RANDOM_ARRAYS(100, int, sorting::simple::InsertionSort, false)
}

// *********************************************************************
TEST(SimpleSorts, InsertionSortSortedDouble)
{
    VERIFY_SORTING_INPLACE_SORTED_ARRAY(100, double, sorting::simple::InsertionSort, false);
}

// *********************************************************************
TEST(SimpleSorts, InsertionSortSortedInt)
{
    VERIFY_SORTING_INPLACE_SORTED_ARRAY(100, int, sorting::simple::InsertionSort, false);
}

// *********************************************************************
TEST(SimpleSorts, InsertionSortInvSortedDouble)
{
    VERIFY_SORTING_INPLACE_INV_SORTED_ARRAY(100, double, sorting::simple::InsertionSort, false);
}

// *********************************************************************
TEST(SimpleSorts, InsertionSortInvSortedInt)
{
    VERIFY_SORTING_INPLACE_INV_SORTED_ARRAY(100, int, sorting::simple::InsertionSort, false);
}

// #####################################################################
// #####################################################################

// *********************************************************************
TEST(SimpleSorts, SelectionSortMultipleSizesDouble)
{
    const double to_sorts[] = {6.0,   5.0,  3.0,  1.0,  2.4, 4.0, 10.0, 7.0,
                               3.42, 32.2, 44.2, 56.3, 67.9, 3.2, 44.2, 2.0};

    VERIFY_SORTING_INPLACE_FIXED_SIZE_ARRAYS(16, double, to_sorts, sorting::simple::SelectionSort, false);
}

// *********************************************************************
TEST(SimpleSorts, SelectionSortMultipleSizesInt)
{
    const double to_sorts[] = {6,  5,  3,  1,  2, 4, 10, 7,
                               3, 32, 44, 56, 67, 3, 44, 2};

    VERIFY_SORTING_INPLACE_FIXED_SIZE_ARRAYS(16, int, to_sorts, sorting::simple::SelectionSort, false);
}

// *********************************************************************
TEST(SimpleSorts, SelectionSortKnownResultDouble)
{
    const double to_sorts[] = {6.0,   5.0,  3.0,  1.0,  2.4, 4.0, 10.0, 7.0,
                               3.42, 32.2, 44.2, 56.3, 67.9, 3.2, 44.2, 2.0};
    const double known_sorted[] = { 1.0, 2.0,  2.4,  3.0,  3.2,  3.42,  4.0,  5.0,
                                    6.0, 7.0, 10.0, 32.2, 44.2, 44.2,  56.3, 67.9};

    VERIFY_SORTING_INPLACE_FIXED_SIZE_ARRAYS_AND_COMPARE(16, double, to_sorts, known_sorted, sorting::simple::SelectionSort, false);
}

// *********************************************************************
TEST(SimpleSorts, SelectionSortKnownResultInt)
{
    const double to_sorts[] = {6,   5,  3,  1,  2, 4, 10, 7,
                               3, 32, 44, 56, 67, 3, 44, 2};
    const double known_sorted[] = { 1, 2,  2,  3,  3,  3,  4,  5,
                                    6, 7, 10, 32, 44, 44,  56, 67};

    VERIFY_SORTING_INPLACE_FIXED_SIZE_ARRAYS_AND_COMPARE(16, int, to_sorts, known_sorted, sorting::simple::SelectionSort, false);
}

// *********************************************************************
TEST(SimpleSorts, SelectionSortMultipleSizesRandomDouble)
{
    VERIFY_SORTING_INPLACE_RANDOM_ARRAYS(100, double, sorting::simple::SelectionSort, false)
}

// *********************************************************************
TEST(SimpleSorts, SelectionSortMultipleSizesRandomInt)
{
    VERIFY_SORTING_INPLACE_RANDOM_ARRAYS(100, int, sorting::simple::SelectionSort, false)
}

// *********************************************************************
TEST(SimpleSorts, SelectionSortSortedDouble)
{
    VERIFY_SORTING_INPLACE_SORTED_ARRAY(100, double, sorting::simple::SelectionSort, false);
}

// *********************************************************************
TEST(SimpleSorts, SelectionSortSortedInt)
{
    VERIFY_SORTING_INPLACE_SORTED_ARRAY(100, int, sorting::simple::SelectionSort, false);
}

// *********************************************************************
TEST(SimpleSorts, SelectionSortInvSortedDouble)
{
    VERIFY_SORTING_INPLACE_INV_SORTED_ARRAY(100, double, sorting::simple::SelectionSort, false);
}

// *********************************************************************
TEST(SimpleSorts, SelectionSortInvSortedInt)
{
    VERIFY_SORTING_INPLACE_INV_SORTED_ARRAY(100, int, sorting::simple::SelectionSort, false);
}
