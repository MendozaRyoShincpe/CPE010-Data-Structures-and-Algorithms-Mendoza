#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int max_size = 100;

// This function will display the random values
void displayValues(int dataset[])
{
    for (int i = 0; i < max_size; i++)
    {
        std::cout << dataset[i] << " ";
    }
}

int main()
{
    int dataset[max_size];

    // Generate a different set of random numbers each time
    srand(time(0));

    // Generate 100 random values from 1 to 100
    for (int i = 0; i < max_size; i++)
    {
        dataset[i] = rand() % 100;
    }

    // Display the random values
    std::cout << "Random Values:\n";
    displayValues(dataset);

    std::cout << "\n\nBubble Sort:\n";
    bubbleSort(dataset, max_size);
    displayValues(dataset);

    std::cout << "\n\nInsertion Sort:\n";
    insertionSort(dataset, max_size);
    displayValues(dataset);

    std::cout << "\n\nSelection Sort:\n";
    selectionSort(dataset, max_size);
    displayValues(dataset);


    return 0;
}