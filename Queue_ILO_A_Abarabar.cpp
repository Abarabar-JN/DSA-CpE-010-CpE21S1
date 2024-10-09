#include <iostream>
#include <queue>
#include <string>

using namespace std;

void display(std::queue<string> a) { 
    std::queue<string> c = a;
    while (!c.empty()) {
        std::cout << " " << c.front();
        c.pop();
    }
    std::cout << "\n";
}

int main() {
    std::queue<string> a;

    // Uses push to add student names directly to the queue
    a.push("Karl");
    a.push("Sanford");
    a.push("Alston");
    a.push("Benedict");
    a.push("Jaypee");

    std::cout << "The queue a is:";
    display(a);
    
    std::cout << "a.empty():" << a.empty() << "\n"; //Use empty to test whether the queue is empty
    std::cout << "a.size():" << a.size() << "\n"; //Use size to determine the size of the queue
    std::cout << "a.front():" << a.front() << "\n"; //Use front to access the topmost element
    std::cout << "a.back():" << a.back() << "\n"; //Use back to access the last element

    std::cout << "a.pop():"; //Use pop to remove the topmost element
    a.pop();
    display(a);

    // Use emplace to add and display a new name
    a.emplace("Tristan");
    std::cout << "a.emplace():";
    display(a);

    // Use to create Queue B
    std::queue<string> b;
    b.push("Cyre");
    b.push("Archie");
    b.push("Zaida");
    b.push("Johnville");
    b.push("Jeymz");
    
    std::cout << "Queue b is:"; //Use to print Queue B
    display(b);
    
    // Use to swap the variables between Queue a and b
    a.swap(b);
    std::cout << "After swapping, queue a is now:";
    display(a);
    std::cout << "After swapping, queue b is now:";
    display(b);

    return 0;
}

