#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <algorithm> 

template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    // Step 1: For i = 0 to N-1 repeat step 2
    for (size_t i = 0; i < arrSize - 1; i++) {
        // Step 2: For J = i + 1 to N – I repeat
        for (size_t j = 0; j < arrSize - i - 1; j++) {
            // Step 3: if A[J] > A[i]
            if (arr[j] > arr[j + 1]) {
                // Swap A[J] and A[i]
                std::swap(arr[j], arr[j + 1]);
            }
            //[End of Inner for loop]
        }
        //[End of Outer for loop]
    }
    // Step 4: Exit
}

template <typename T>
int Routine_Smallest(T A[], int K, const int arrSize);

template <typename T>
void selectionSort(T arr[], const int N) {
    //Step 1: Repeat Steps 2 and 3 for K = 1 to N-1
    for (int i = 0; i < N - 1; i++) {
        //Step 2: Call routine smallest(A, K, N,POS)
        int POS = Routine_Smallest(arr, i, N);
        //Step 3: Swap A[K] with A [POS]
        std::swap(arr[i], arr[POS]);
    }
}

template <typename T>
int Routine_Smallest(T A[], int K, const int arrSize) {
    int position = K;
    //Step 1: [initialize] set smallestElem = A[K]
    T smallestElem = A[K];
    //Step 2: [initialize] set POS = K
    position = K;
    //Step 3: for J = K+1 to N -1,repeat
    for (int J = K + 1; J < arrSize; J++) {
        if (A[J] < smallestElem) {
            smallestElem = A[J];
            position = J;
        }
    }
    return position; //Step 4: return POS
}

template <typename T>
void insertionSort(T arr[], const int N) {
    //Step 1: Repeat Steps 2 to 5 for K = 1 to N-1
    for (int K = 1; K < N; K++) {
        //Step 2: set temp = A[K]
        T temp = arr[K];
        //Step 3: set J = K – 1
        int J = K - 1;
        //Step 4: Repeat while temp <=A[J]
        while (J >= 0 && arr[J] > temp) {
            //set A[J + 1] = A[J]
            arr[J + 1] = arr[J];
            //set J = J – 1
            J--;
            //[end of inner loop]
        }
        //Step 5: set A[J + 1] = temp
        arr[J + 1] = temp;
        //[end of loop]
    }
    //Step 6: exit
}

#endif 

