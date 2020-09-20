/*
Created by Visual studio c++ 2019.

This program(written in c) compares the two common sorting algorithms.Bubble sort and quick sort.
Bubble sort requires no extra memory and replaces the array in place however the time complexity is O(n2).
Quick sort has an average time complexity of O(nlogn).However, it requires more extra memory for recursive call backsand partitioning.
This extra memory is equal to size of the partitioning in quick sort which is usually log n.

In Embedded systems for large arrays Quicksort is more efficient because it is fasterand extra memory that is needed from the stack is not growing quadratically or even linearly.

There are other sorting algorithms(e.g.merging sort, or count base) which also can be faster than quick sort but since they are not memory efficient I believe they are not good choice for Embedded systems.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Change this to increase the array size. This cannot be 0. 
#define Array_SIZE 2000

#pragma region FunctionDeclarations
void PrintArray(int* inputArray, int length);
int Partition(int* inputArray, int start , int end);
void swap(int* inputArray, int index1, int index2);
void QuickSort(int* inputArray, int start, int end); 
#pragma endregion

int QuickSortLoopCounter = 0;
int main()
{
    printf("Following is the comparison between two algorithms to sort arrays.\n\n"); 

    int intArray[Array_SIZE];
    int intArrayBubbleSort[Array_SIZE];
    int intArrayQuickSort[Array_SIZE];
    clock_t bubbleSortStart, bubbleSortEnd; 
    clock_t quickSortStart, quickSortEnd; 

#pragma region RandomNumberGeneration
    srand(time(NULL));
    printf("%d random numbers are generated as follows:\n\n" , Array_SIZE);
    for (int i = 0; i < Array_SIZE; i++) {
        intArray[i] = rand() % 999;
        intArrayBubbleSort[i] = intArray[i];
        intArrayQuickSort[i] = intArray[i];
        printf("%d ", intArray[i]);
    }
    printf("\n\n");
#pragma endregion

#pragma region BubbleSort
    bubbleSortStart = clock(); 
    for (int i = 0; i < Array_SIZE; i++) {
        for (int j = i; j < Array_SIZE; j++) {
            if (intArrayBubbleSort[i] > intArrayBubbleSort[j]) 
                swap(intArrayBubbleSort, i, j); 
        }
    }
    bubbleSortEnd = clock();

    printf("Bubble sort has finished in %d (ms) and Used %d bytes of memory.Bubble sorted numbers are as follows: \n" , bubbleSortEnd - bubbleSortStart, sizeof(int) * (Array_SIZE + 1 ));
    PrintArray(intArrayBubbleSort, Array_SIZE);
#pragma endregion

#pragma region QuickSort
    quickSortStart = clock(); 
    QuickSort(intArrayQuickSort, 0, Array_SIZE - 1);
    quickSortEnd = clock();
    printf("\n\nQuick Sort has finished in %d (ms) and Used %d bytes of memory.Quick sorted numbers are as follows: \n", quickSortEnd - quickSortStart, sizeof(int) * (Array_SIZE + 1 + QuickSortLoopCounter));
    PrintArray(intArrayQuickSort, Array_SIZE);
#pragma endregion

    char finalCh = getchar();
    return 0;
}

#pragma region FunctionsImplementations
void PrintArray(int* inputArray, int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", inputArray[i]);
    printf("\n");
}

int Partition(int* inputArray, int start , int end) {
    int pivot = inputArray[end];
    int boundary = start-1;
    for (int i = start; i <= end; i++) {
        if (inputArray[i] <= pivot) 
            swap(inputArray, i, ++boundary);
    }

    return boundary; 
}

void QuickSort(int* inputArray, int start, int end) {
    if (start >= end)
        return; 

    int boundary = Partition(inputArray, start , end);
    QuickSort(inputArray, start, boundary - 1); 
    QuickSort(inputArray, boundary + 1, end); 
    QuickSortLoopCounter++; 
}

void swap(int* inputArray, int index1, int index2) {
    int temp = inputArray[index1];
    inputArray[index1] = inputArray[index2];
    inputArray[index2] = temp;
}
#pragma endregion