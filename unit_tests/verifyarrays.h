#ifndef SORTING_UNIT_TESTS_VERIFYARRAYS_H_
#define SORTING_UNIT_TESTS_VERIFYARRAYS_H_

bool VerifyIfAllNotNaN(double const * const sorted, const int N)
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

bool VerifyIfOrdered(double const * const sorted, const int N)
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

bool VerifySortedUnique(double const * const original, double const * const sorted, const int N)
{
    // Make sure every element of the original array is present in the sorted one
    // Make a temporary copy of the arrays
    double *tmp_orig = new double[N];
    double *tmp_sort = new double[N];
    memcpy(tmp_orig, original, N*sizeof(double));
    memcpy(tmp_sort, sorted,   N*sizeof(double));
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
