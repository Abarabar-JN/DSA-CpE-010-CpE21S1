#include <iostream>
#include <string>

// Use to create a Job class representing a print job with user ID, name, and number of pages
class Job {
public:
    int jobID;                
    std::string userName;     
    int pages;                

    // Use to intialize Job as an object
    Job(int id, const std::string& user, int pageCount) 
        : jobID(id), userName(user), pages(pageCount) {}
};

// Use to create a Node class for linked list to contain and hold a job which can be added more
class Node {
public:
    Job* job;                
    Node* next;              


    Node(Job* j) : job(j), next(nullptr) {}
};

// Use to create a Printer class that represents the print queue
class Printer {
private:
    Node* front;             
    Node* rear;              

public:
    // Use to create or initialize an empty queue for the printer queue
    Printer() : front(nullptr), rear(nullptr) {}

    // Use to intialize a way to add a new job to the printer queue
    void addJob(Job* job) {
        Node* newNode = new Node(job); 
        if (rear) {
            rear->next = newNode;       
        } else {
            front = newNode;            
        }
        rear = newNode;                 
        std::cout << "Job " << job->jobID << " is added by " << job->userName << " (" << job->pages << " pages)." << std::endl;
    }

    // Use to make a way to intialize all jobs within the queue
    void processJobs() {
        while (front) {
            Job* currentJob = front->job; 
            std::cout << "Processing Job " << currentJob->jobID << " from " << currentJob->userName << " (" << currentJob->pages << " pages)." << std::endl;
            //Use to control the major memory and process of the nodes
            delete currentJob;            
            Node* temp = front;           
            front = front->next;          
            delete temp;                  
        }
        rear = nullptr;                  
    }

    // Use to create a Destructor to clean up the queue
    ~Printer() {
        while (front) {
            Node* temp = front;          
            front = front->next;         
            delete temp->job;            
            delete temp;                 
        }
    }
};

int main() {
    Printer printer; 

    // Use to allow input to initialize the process 
    printer.addJob(new Job(1, "Marky", 10));
    printer.addJob(new Job(2, "DD", 15));
    printer.addJob(new Job(3, "Joey", 8));

    
    printer.processJobs();

    return 0;
}

