# Code Analysis of Non Recursive Binary Search

The code consists of two main parts:
1. **Bubble Sort (`Sort` function)**: This sorts the array.
2. **Binary Search (`BinarySearch` function)**: This searches for a key in the sorted array.

## Bubble Sort Analysis

Bubble Sort works by repeatedly swapping adjacent elements that are out of order. The nested loops iterate over the array, with the outer loop running `n` times and the inner loop running `n-i-1` times, where `i` is the current index of the outer loop.

- **Worst-case time complexity**: \(O(n^2)\)
  - This occurs when the array is in reverse order, requiring the maximum number of swaps.
- **Best-case time complexity**: \(O(n)\)
  - This occurs when the array is already sorted, and no swaps are needed. However, in this implementation, the best-case scenario still runs \(O(n^2)\) because there is no early exit mechanism.
- **Average-case time complexity**: \(O(n^2)\)
  - This is the average scenario over all possible inputs.

## Binary Search Analysis

Binary Search operates by repeatedly dividing the search interval in half. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. Otherwise, narrow it to the upper half.

- **Worst-case time complexity**: \(O(\log n)\)
  - This occurs when the key is not present, and we must reduce the search interval to zero.
- **Best-case time complexity**: \(O(1)\)
  - This occurs when the key is found at the first mid comparison.
- **Average-case time complexity**: \(O(\log n)\)
  - This is the average scenario over all possible inputs.

## Overall Time Complexity of the Program

The overall time complexity of the program is dominated by the sorting step, as sorting is typically more time-consuming than searching, ie dominated by Bubble Sort: \(O(n^2)\) in all cases.
