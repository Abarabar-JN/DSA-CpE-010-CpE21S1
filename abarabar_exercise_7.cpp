#include <iostream>
using namespace std;

// Function to display the array
void displayArray(int arr[], int size) {
    cout << "Array: "; 
    // Iterate through the array and print each element followed by a space
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl; 
}

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0; 
    int right = size - 1; 
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        }

        if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return -1; 
}

int main() {
    //Use to initialize an array and measure it's size aid in searching by labelling each value
    int arr[] = {2, 3, 4, 5, 8}; // Array must be sorted for binary search to work
    int size = sizeof(arr) / sizeof(arr[0]); 
    int target; 
    
    // Displays the array
    displayArray(arr, size);
    
    // Allows the user to enter a target number to search for and print it out
    cout << "Enter a number to search: ";
    cin >> target; 
    
    // Perform binary search on the array
    int result = binarySearch(arr, size, target);
    
    // If the element is found, print its index
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        // If the element is not found, print a message
        cout << "Element not found." << endl;
    }
    
    return 0; 
}
