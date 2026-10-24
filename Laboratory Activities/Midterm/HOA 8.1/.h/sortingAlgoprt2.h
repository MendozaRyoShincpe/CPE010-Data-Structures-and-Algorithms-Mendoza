#ifndef SORTINGALGOPRT2_H
#define SORTINGALGOPRT2_H

// =========================
// SHELL SORT
// =========================
template <typename T>
void shellSort(T arr[], int size)
{
    // Start with half of the array as the gap
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        // Perform insertion sort using the gap
        for (int i = gap; i < size; i++)
        {
            T temp = arr[i];
            int j;

            // Move elements that are greater than temp
            // to the right
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            // Place temp in its correct position
            arr[j] = temp;
        }
    }
}


// =========================
// MERGE SORT
// =========================

// Merge two sorted parts of the array
template <typename T>
void merge(T arr[], int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Temporary arrays
    T* leftArr = new T[n1];
    T* rightArr = new T[n2];

    // Copy values to temporary arrays
    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = arr[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    // Merge the two arrays in sorted order
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements from left array
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements from right array
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}


// Merge Sort function
template <typename T>
void mergeSort(T arr[], int left, int right)
{
    // Continue dividing while there is more than one element
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        // Sort the left half
        mergeSort(arr, left, middle);

        // Sort the right half
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}


// =========================
// QUICK SORT
// =========================

// Partition the array around a pivot
template <typename T>
int partition(T arr[], int low, int high)
{
    // Use the last element as the pivot
    T pivot = arr[high];

    int i = low - 1;

    // Compare each element with the pivot
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            // Swap elements
            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot in its correct position
    T temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}


// Quick Sort function
template <typename T>
void quickSort(T arr[], int low, int high)
{
    if (low < high)
    {
        // Get the pivot position
        int pivot = partition(arr, low, high);

        // Sort the left side
        quickSort(arr, low, pivot - 1);

        // Sort the right side
        quickSort(arr, pivot + 1, high);
    }
}

#endif