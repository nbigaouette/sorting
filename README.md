# sorting

This is a simple C++ template library implementing different sorting algorithms.
Sorting functions are encapsulated into namespaces.


## Algorithms
Implemented algorithms are (more to come):
### Simple sorts
* Insertion sort: *sorting::simple::InsertionSort()*
* Selection sort: *sorting::simple::SelectionSort()*

### Efficient sorts
* Merge sort (non-recursive, bottom-up): *sorting::efficient::MergeSort()*
* Merge sort (recursive, top-down): *sorting::efficient::MergeSortRecursive()*


## Usage
It's a template library, so just include it:

```C++
#include "sorting.h"
```

## Notes
Values are either swapped (using *std::swap()*) or moved (using *memmove()*). One has to make
sure the array type used support these operations. Basic C++ types (integers, doubles, etc.) don't
have any problem.


## Testing
To validate the different implementations, unit tests are used. A copy of [gtest](https://code.google.com/p/googletest/)
(version 1.7.0, BSD license) is included.

To run all unit tests, use cmake:

```bash
$ cd sorting.git/build
$ cmake ..
$ make
$ ./unit_tests/libsorting_utests
```

As of now, 10 unit tests are run for each sorting algorithms:
- The first N elements (with N from 1 to 16) of an array of 16 integers is sorted;
- The first N elements (with N from 1 to 16) of an array of 16 doubles is sorted;
- An array of 16 integers is sorted and compared to the required result;
- An array of 16 doubles is sorted and compared to the required result;
- Arrays of N integers (with N from 1 to 100) with random values are sorted (current time as seed);
- Arrays of N doubles (with N from 1 to 100) with random values are sorted (current time as seed);
- Arrays of N integers (with N from 1 to 100) with values already sorted are sorted;
- Arrays of N doubles (with N from 1 to 100) with values already sorted are sorted;
- Arrays of N integers (with N from 1 to 100) with values (inversely) sorted are sorted;
- Arrays of N doubles (with N from 1 to 100) with values (inversely) sorted are sorted;

For each test, an array is considered sorted if:
- Every element is smaller or equal (<=) then its next neighbour in the array;
- All elements in the array to sort is present (using ==) in the sorted array;
- All elements in the sorted array is present (using ==) in the array to sort;
- No NaN is present in the sorted array;


## License

This code is distributed under the terms of the BSD 3 clause and is Copyright 2014 Nicolas Bigaouette.
