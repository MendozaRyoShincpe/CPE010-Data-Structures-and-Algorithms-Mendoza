#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgoprt2.h"

const int SIZE = 100;

// Function to display the array
void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << "\t";

        // Move to the next line every 10 values
        if ((i + 1) % 10 == 0)
        {
            std::cout << std::endl;
        }
    }
}

// Function to copy one array into another
void copyArray(int source[], int destination[], int size)
{
    for (int i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }
}

int main()
{
    // Create the original dataset
    int values[SIZE];

    // Create separate arrays for each sorting algorithm
    int shellValues[SIZE];
    int mergeValues[SIZE];
    int quickValues[SIZE];

    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate 100 random values from 1 to 99
    for (int i = 0; i < SIZE; i++)
    {
        values[i] = (std::rand() % 99) + 1;
    }

    // Copy the same dataset for each sorting algorithm
    copyArray(values, shellValues, SIZE);
    copyArray(values, mergeValues, SIZE);
    copyArray(values, quickValues, SIZE);

    // =========================
    // ORIGINAL ARRAY
    // =========================
    std::cout << "========================================\n";
    std::cout << "       ORIGINAL UNSORTED ARRAY\n";
    std::cout << "========================================\n";

    displayArray(values, SIZE);


    // =========================
    // SHELL SORT
    // =========================
    std::cout << "\n========================================\n";
    std::cout << "             SHELL SORT\n";
    std::cout << "========================================\n";

    shellSort(shellValues, SIZE);

    displayArray(shellValues, SIZE);


    // =========================
    // MERGE SORT
    // =========================
    std::cout << "\n========================================\n";
    std::cout << "             MERGE SORT\n";
    std::cout << "========================================\n";

    mergeSort(mergeValues, 0, SIZE - 1);

    displayArray(mergeValues, SIZE);


    // =========================
    // QUICK SORT
    // =========================
    std::cout << "\n========================================\n";
    std::cout << "             QUICK SORT\n";
    std::cout << "========================================\n";

    quickSort(quickValues, 0, SIZE - 1);

    displayArray(quickValues, SIZE);


    std::cout << "\n========================================\n";
    std::cout << "        SORTING COMPLETED!\n";
    std::cout << "========================================\n";

    return 0;
}