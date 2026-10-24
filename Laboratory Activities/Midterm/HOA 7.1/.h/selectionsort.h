#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include <iostream>

template <typename T>
void selectionSort(T arr[], int arrSize)
{
    for (int i = 0; i < arrSize - 1; i++)
    {
        int smallest = i;

        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[j] < arr[smallest])
            {
                smallest = j;
            }
        }

        std::swap(arr[i], arr[smallest]);
    }
}

#endif