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

## Testing
Unit tests are used to validate the implementations. To run them, use cmake:

```bash
$ cd sorting.git/build
$ cmake ..
$ make
$ ./unit_tests/libsorting_utests
```

## License

This code is distributed under the terms of the BSD 3 clause and is Copyright 2014 Nicolas Bigaouette.
