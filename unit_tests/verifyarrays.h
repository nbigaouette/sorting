#ifndef SORTING_UNIT_TESTS_VERIFYARRAYS_H_
#define SORTING_UNIT_TESTS_VERIFYARRAYS_H_

template <class T>
bool VerifyIfAllNotNaN(T const * const sorted, const int N)
{
    // Verify any NaN
    for (int i = 1 ; i < N ; i++)
    {
        if (isnan(sorted[i]))
        {
            return false;
        }
    }
    return true;
}

template <class T>
bool VerifyIfOrdered(T const * const sorted, const int N)
{
    // Make sure array is ordered
    for (int i = 1 ; i < N ; i++)
    {
        if (sorted[i] <= sorted[i-1])
        {
            return false;
        }
    }
    return true;
}

template <class T>
bool VerifySortedUnique(T const * const original, T const * const sorted, const int N)
{
    // Make sure every element of the original array is present in the sorted one
    // Make a temporary copy of the arrays
    int *i_orig = new int[N];
    for (int i = 0 ; i < N ; i++)
    {
        i_orig[i] = -1;
    }
    // Flag every element of the (copied) arrays that match.
    for (int i = 0 ; i < N ; i++)
    {
        for (int j = 0 ; j < N ; j++)
        {
            if (original[i] == sorted[j])
            {
                // We found a matching element. Verify if this element is not a dupplicate.
                bool duplicate = false;
                for (int k = 0 ; k < i ; k++)
                {
                    if (i_orig[k] == j)
                    {
                        duplicate = true;
                        break;
                    }
                }
                if (not duplicate)
                {
                    i_orig[i] = j;
                    break;
                }
            }
        }
    }

    // Now verify that every element was found
    bool is_unique = true;
    for (int i = 0 ; i < N ; i++)
    {
        if (i_orig[i] == -1)
        {
            is_unique = false;
        }
    }
    delete[] i_orig;

    if (is_unique)
    {
        return true;
    }
    else
    {
        return false;
    }
}


#endif  // SORTING_UNIT_TESTS_VERIFYARRAYS_H_
