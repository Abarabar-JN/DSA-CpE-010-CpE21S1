#include <iostream>

// Sets Template Class for Queue
template <typename T>
class Queue {
private: //Sets the certain elements for the data input
    T* data;                
    size_t capacity;        
    size_t size;            
    size_t front;           
    size_t back;            

    // Use to manage the queue size when capacity is reached
    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity]; 
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[(front + i) % capacity]; 
        }
        delete[] data;       
        data = new_data;     
        capacity = new_capacity; 
        front = 0;          
        back = size;        
    }

public:
    // Initilaizes the initial capacity
    Queue(size_t initial_capacity = 10)
        : capacity(initial_capacity), size(0), front(0), back(0) {
        data = new T[capacity]; 
    }

    // Initializes Destructor
    ~Queue() {
        delete[] data;
    }

    // Makes a constructor for copying elements
    Queue(const Queue& other)
        : capacity(other.capacity), size(other.size), front(other.front), back(other.back) {
        data = new T[capacity]; 
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[(other.front + i) % other.capacity]; 
        }
    }

    // Use to set the functions to be used
    Queue& operator=(const Queue& other) {
        if (this != &other) {
            delete[] data;    
            capacity = other.capacity;
            size = other.size;
            front = other.front;
            back = other.back;
            data = new T[capacity]; 
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[(other.front + i) % other.capacity]; 
            }
        }
        return *this; 
    }

    // Use to check if queue is empty
    bool empty() const {
        return size == 0;
    }

    // Use to get current size
    size_t getSize() const {
        return size;
    }

    // Use to clear the queue
    void clear() {
        size = front = back = 0;
    }

    // Use to view the front element
    T* peekFront() {
        return empty() ? nullptr : &data[front];
    }

    // Use to view the back element
    T* peekBack() {
        return empty() ? nullptr : &data[(back - 1 + capacity) % capacity];
    }

    // Use to add an element to the back
    bool enqueue(const T& value) {
        if (size == capacity) {
            resize(capacity * 2); 
        }
        data[back] = value; 
        back = (back + 1) % capacity; 
        ++size; 
        return true;
    }

    // Use to remove front element
    bool dequeue() {
        if (empty()) return false;
        front = (front + 1) % capacity; // Move front index
        --size; // Decrease size
        return true;
    }
};

int main() {
    Queue<int> q; 

    std::cout << "Initial queue size: " << q.getSize() << "\n";

    // Use to enqueue elements from a range and print it out
    for (int i = 1; i <= 5; ++i) {
        q.enqueue(i);
        std::cout << "Enqueued: " << i << "\n";
    }

    // Use to peak front to back in the initialized queue of elements
    if (int* front = q.peekFront()) {
        std::cout << "Front: " << *front << "\n";
    }
    
    if (int* back = q.peekBack()) {
        std::cout << "Back: " << *back << "\n";
    }

    // Use to Dequeue elements until queue is empty
    while (!q.empty()) {
        if (int* front = q.peekFront()) {
            std::cout << "Dequeued: " << *front << "\n";
            q.dequeue();
        }
    }

    
    std::cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << "\n";

    // Use to enqueue more elements to utilize other functions
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    std::cout << "Size after enqueues: " << q.getSize() << "\n";

    if (int* front = q.peekFront()) {
        std::cout << "Front: " << *front << "\n";
    }

    if (int* back = q.peekBack()) {
        std::cout << "Back: " << *back << "\n";
    }

    q.dequeue();
    std::cout << "Size after one dequeue: " << q.getSize() << "\n";

    // Use to clear and check queue size
    q.clear();
    std::cout << "Size after clear: " << q.getSize() << "\n";
    std::cout << (q.empty() ? "Queue is empty" : "Queue is not empty") << "\n";

    return 0; 
}
