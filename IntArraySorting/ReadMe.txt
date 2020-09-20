				Created by Visual studio c++ 2019.

This program (written in c) compares the two common sorting algorithms. Bubble sort and quick sort.
Bubble sort requires no extra memory and replaces the array in place however the time complexity is O(n2).
Quick sort has an average time complexity of O(nlogn). However, it requires more extra memory for recursive call backs and partitioning. 
This extra memory is equal to size of the partitioning in quick sort which is usually log n. 

In Embedded systems for large arrays Quicksort is more efficient because it is faster and extra memory that is needed from the stack is not growing quadratically or even linearly. 

There are other sorting algorithms (e.g. merging sort, or count base) which also can be faster than quick sort but since they are not memory efficient I believe they are not good choice for Embedded systems.
