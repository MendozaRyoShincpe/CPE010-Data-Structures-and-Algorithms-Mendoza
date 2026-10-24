#ifndef SORTINGALGO_H
#define SORTINGALGO_H
#include <iostream>

template <typename T>
void bubbleSort(T arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[j] < arr[i])
            {
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

template <typename T>
void insertionSort(T arr[], int arrSize)
{
    int k = 1, j, temp;

    while (k < arrSize)
    {
        temp = arr[k]; // 1
        j = k - 1;

        while (j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j]; //2 
            j--;
        }

        arr[j + 1] = temp; //3
        k++;
    }
}

template<typename T>
int routine_smallest(T A[], int maxSize, int k){

    int position;
    T smallestElem = A[k];

    for(int J = k+1; J < maxSize; J++){
        if(A[J] < smallestElem){
            smallestElem = A[J];
            position = J;
        }
    }

    return position;

}

template <typename T>
void selectionSort(T arr[], int arrSize){
    int POS, temp;

    for(int i = 0; i < arrSize; i++){
        POS = routine_smallest(arr, arrSize, i); //returns the index of the sm...
        std::swap(arr[i], arr[POS]);
    }
}
#endif