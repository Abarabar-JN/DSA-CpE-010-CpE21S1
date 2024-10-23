#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm> 

const int max_size = 100;

// Function to perform insertion sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        // Sort the left sublist using insertion sort
        insertionSort(arr + low, p - low);
        
        // Sort the right sublist using insertion sort
        insertionSort(arr + p + 1, high - p);
    }
}

int main() {
    int dataset[max_size];
    srand(static_cast<unsigned int>(time(0))); // Random value generation

    // Generate random array of values from 0 to 100
    for (int i = 0; i < max_size; ++i) {
        dataset[i] = rand() % 100;
    }
    
    // Display the randomized array
    std::cout << "Randomized Array:" << std::endl;
    for (int i = 0; i < max_size; i++) {
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;

    // Sort and display results for Quick Sort with insertion sort for sublists
    int quickSortArray[max_size];
    std::copy(dataset, dataset + max_size, quickSortArray);
    quickSort(quickSortArray, 0, max_size - 1);
    
    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Sorted Array with Insertion Sort for Sublists:" << std::endl;
    for (int i = 0; i < max_size; i++) {
        std::cout << quickSortArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

