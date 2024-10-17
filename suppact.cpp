#include <iostream>
#include <cstdlib>
#include <ctime>

//Use to set Bubble Sort Operation
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    const int size = 100;
    int A[size];
    int voteCount[5] = {0};

    // Use to create random numbers per execution
    std::srand(std::time(0));

    // Generates random amount of numbers from 1 - 5
    for (int i = 0; i < size; i++) {
        A[i] = std::rand() % 5 + 1; // Random number between 1 and 5
    }

    bubbleSort(A, size);

    // Use to count the numbers of each variable for the votes
    for (int i = 0; i < size; i++) {
        voteCount[A[i] - 1]++;
    }

    // Use to see which candidate or number appears the most to set the winner condition
    int maxVotes = 0, winnerIndex = -1;
    for (int i = 0; i < 5; i++) {
        if (voteCount[i] > maxVotes) {
            maxVotes = voteCount[i];
            winnerIndex = i;
        }
    }

    // Used to Output Array
    std::cout << "Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    //Use to output the number of votes per candidate
    std::cout << "Votes Per Candidate:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Candidate " << (i + 1) << ": " << voteCount[i] << " votes" << std::endl;
    }
    //Use to output the winning candidate
    std::cout << "Winning Candidate: Candidate " << (winnerIndex + 1) << " with " << maxVotes << " votes" << std::endl;

    return 0;
}
