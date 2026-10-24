#include <iostream>
#include <cstdlib>
#include <ctime>
#include "selectionsort.h"

const int max_size = 100;

// This function will display the votes
void displayValues(int votes[])
{
    for (int i = 0; i < max_size; i++)
    {
        std::cout << votes[i] << " ";

        if ((i + 1) % 20 == 0)
        {
            std::cout << std::endl;
        }
    }
}

int main()
{
    int votes[max_size];

    // This will generate a different set of random numbers each time
    srand(time(0));

    // This will enerate 100 random votes from 1 to 5
    for (int i = 0; i < max_size; i++)
    {
        votes[i] = rand() % 5 + 1;
    }

    // Sort the votes
    selectionSort(votes, max_size);

    std::cout << "Sorted Array:\n";
    displayValues(votes);

    // Count votes
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;

    for (int i = 0; i < max_size; i++)
    {
        if (votes[i] == 1)
            count1++;
        else if (votes[i] == 2)
            count2++;
        else if (votes[i] == 3)
            count3++;
        else if (votes[i] == 4)
            count4++;
        else if (votes[i] == 5)
            count5++;
    }

    // Display vote count
    std::cout << "\nVote Count:\n";
    std::cout << "Candidate 1: " << count1 << " votes\n";
    std::cout << "Candidate 2: " << count2 << " votes\n";
    std::cout << "Candidate 3: " << count3 << " votes\n";
    std::cout << "Candidate 4: " << count4 << " votes\n";
    std::cout << "Candidate 5: " << count5 << " votes\n";

    // Find the winner
    int highest = count1;
    int winner = 1;

    if (count2 > highest)
    {
        highest = count2;
        winner = 2;
    }

    if (count3 > highest)
    {
        highest = count3;
        winner = 3;
    }

    if (count4 > highest)
    {
        highest = count4;
        winner = 4;
    }

    if (count5 > highest)
    {
        highest = count5;
        winner = 5;
    }

    std::cout << "\nWinner: Candidate " << winner << " with " << highest << " votes\n";

    return 0;
}