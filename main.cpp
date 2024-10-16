#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "sorting.h" 

// Used to generate random variables between 0 to 999
void generateRandomArray(std::vector<int>& arr, int size) {
    for (int i = 0; i < size; i++) {
        arr.push_back(rand() % 1000); 
    }
}

// Used to print out array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {//Main file used to implement the sorting of arrays using various algorithms
    std::srand(static_cast<unsigned int>(std::time(nullptr))); 
    const int arraySize = 100; 
    std::vector<int> randomArray;
    generateRandomArray(randomArray, arraySize); 

    std::cout << "Original Array:\n";
    printArray(randomArray);

    // Bubble Sort
    std::vector<int> bubbleArray = randomArray;
    bubbleSort(bubbleArray.data(), bubbleArray.size());
    std::cout << "\n(Bubble Sort):\n";
    printArray(bubbleArray);

    // Selection Sort
    std::vector<int> selectionArray = randomArray;
    selectionSort(selectionArray.data(), selectionArray.size());
    std::cout << "\n(Selection Sort):\n";
    printArray(selectionArray);

    // Insertion Sort
    std::vector<int> insertionArray = randomArray;
    insertionSort(insertionArray.data(), insertionArray.size());
    std::cout << "\n(Insertion Sort):\n";
    printArray(insertionArray);

    return 0;
}

