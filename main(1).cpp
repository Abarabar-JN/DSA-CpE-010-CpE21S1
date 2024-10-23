#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting_algorithms.h"

const int max_size = 100;

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

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

void shellSort(int arr[], int size) {
    for (int interval = size / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int dataset[max_size];
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < max_size; ++i) {
        dataset[i] = rand() % 100;
    }

    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Randomized Array:" << std::endl;
    for (int i = 0; i < max_size; i++) {
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;

    // Quick Sort
    int quickSortArray[max_size];
    std::copy(dataset, dataset + max_size, quickSortArray);
    quickSort(quickSortArray, 0, max_size - 1);
    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Quick Sorted Array:" << std::endl;
    for (int i = 0; i < max_size; i++) {
        std::cout << quickSortArray[i] << " ";
    }
    std::cout << std::endl;

    // Shell Sort
    int shellSortArray[max_size];
    std::copy(dataset, dataset + max_size, shellSortArray);
    shellSort(shellSortArray, max_size);
    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Shell Sorted Array:" << std::endl;
    for (int i = 0; i < max_size; i++) {
        std::cout << shellSortArray[i] << " ";
    }
    std::cout << std::endl;

    // Merge Sort
    int mergeSortArray[max_size];
    std::copy(dataset, dataset + max_size, mergeSortArray);
    mergeSort(mergeSortArray, 0, max_size - 1);
    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Merge Sorted Array" << std::endl;
    for (int i = 0; i < max_size; i++) {
        std::cout << mergeSortArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
