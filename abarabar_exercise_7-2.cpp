#include <iostream>
using namespace std;

// Function to display the array
void displayArray(int arr[], int size) {
    cout << "Array: "; 
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; // Print each element of the array
    }
    cout << endl; 
}

// Function to perform a linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    // Example unsorted array to search in binary 
    int arr[] = {5, 3, 8, 4, 2}; //Array must be unsorted for this
    int size = sizeof(arr) / sizeof(arr[0]); 
    int target; 
    
    // Display the contents of the array
    displayArray(arr, size);
    
    // Allows user to enter a number to search within the array
    cout << "Enter a number to search: ";
    cin >> target; 
    
    // Perform linear search and store the result
    int result = linearSearch(arr, size, target);
    
    // Output the result of the search
    if (result != -1) {
        cout << "Element found at index: " << result << endl; // If found, display index
    } else {
        cout << "Element not found." << endl; // If not found, display message
    }
    
    return 0; 
}

