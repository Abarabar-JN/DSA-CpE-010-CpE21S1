#include <iostream>

// Creates Node structure for each element in the queue to contain data and point to the next node
struct Node {
    int data;   
    Node* next;    

    // Constructor used to initialize a node with a given value
    Node(int value) : data(value), next(nullptr) {}
};

class Queue { 
private:
    Node* front;   
    Node* rear;    

public:
    // Initializes an empty queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Adds an element to the queue
    void Enqueue(int value) {
        Node* newNode = new Node(value); 
        if (front == nullptr) { 
            front = rear = newNode; 
        } else { 
            rear->next = newNode; 
            rear = newNode; 
        }
        std::cout << "Inserted: " << value << std::endl; 
    }

    // Removes one element from the queue
    void DequeueOne() {
        if (front == nullptr) { 
            std::cout << "Queue is empty!" << std::endl;
            return;
        }

        Node* temp = front; 
        front = front->next; 

        std::cout << "Deleted: " << temp->data << std::endl; 
        delete temp; 

        if (front == nullptr) { 
            rear = nullptr; 
        }
    }

    // Displays the current elements in the queue
    void display() {
        Node* temp = front; 
        std::cout << "Queue: ";
        while (temp != nullptr) { 
            std::cout << temp->data << " "; 
            temp = temp->next; 
        }
        std::cout << std::endl; 
    }

    // Checks if the queue is currently empty
    bool isEmpty() {
        return front == nullptr; 
    }
};

int main() { 
    Queue q; 
    int choice, value; 

    while (true) {
        std::cout << "1. Insert to queue\n2. Remove from queue\n3. Display\n4. Exit\nChoose an option: ";
        std::cin >> choice; // Get user choice

        switch (choice) {
            case 1: // Insert a value to the queue
                std::cout << "Enter value to enqueue: ";
                std::cin >> value; 
                q.Enqueue(value); 
                break;
            case 2: // Remove a value from the queue
                if (q.isEmpty()) { 
                    std::cout << "Queue is empty! Cannot remove element from queue." << std::endl;
                } else {
                    q.DequeueOne(); 
                }
                break;
            case 3: // Show current elements in the queue
                q.display(); 
                break;
            case 4: // Exit the program
                std::cout << "Exiting..." << std::endl; 
                return 0; 
            default: 
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    }

    return 0; 
}

