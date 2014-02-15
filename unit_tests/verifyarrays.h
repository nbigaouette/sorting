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
    T *tmp_orig = new T[N];
    T *tmp_sort = new T[N];
    memcpy(tmp_orig, original, N*sizeof(T));
    memcpy(tmp_sort, sorted,   N*sizeof(T));
    // Flag every element of the (copied) arrays that match.
    for (int i = 0 ; i < N ; i++)
    {
        for (int j = 0 ; j < N ; j++)
        {
            // Note that NAN != NAN
            if (tmp_orig[i] == tmp_sort[j])
            {
                tmp_orig[i] = NAN;
                tmp_sort[j] = NAN;
                break;
            }
        }
    }
    // Now verify if one element of the temporary arrays is _not_ NaN.
    // In that case, something went wrong!
    for (int i = 0 ; i < N ; i++)
    {
        if (not isnan(tmp_orig[i]))
        {
            return false;
        }
        if (not isnan(tmp_sort[i]))
        {
            return false;
        }
    }
    delete[] tmp_orig;
    delete[] tmp_sort;

    return true;
}


#endif  // SORTING_UNIT_TESTS_VERIFYARRAYS_H_
