#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Queue {
private:
    ListNode* frontNode; // Points to the front of the queue
    ListNode* rearNode;  // Points to the rear of the queue

public:
    Queue() : frontNode(nullptr), rearNode(nullptr) {}

    // Enqueue operation: Add an element to the rear of the queue
    void enqueue(int x) {
        ListNode* newNode = new ListNode(x);
        if (isEmpty()) {
            frontNode = rearNode = newNode; // First element in the queue
        } else {
            rearNode->next = newNode; // Link the new node to the rear
            rearNode = newNode;       // Update the rear pointer
        }
    }

    // Dequeue operation: Remove and return the front element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue from an empty queue." << endl;
            return -1; // Indicate an error
        }
        int value = frontNode->val;
        ListNode* temp = frontNode;
        frontNode = frontNode->next; // Move the front pointer to the next node
        delete temp;
        if (frontNode == nullptr) {  // If the queue becomes empty
            rearNode = nullptr;
        }
        return value;
    }

    // Peek operation: Return the front element without removing it
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty! No front element." << endl;
            return -1; // Indicate an error
        }
        return frontNode->val;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return frontNode == nullptr;
    }

    // Destructor: Clean up dynamically allocated memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue queue;

    // Test operations
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    
    cout << "Front of queue: " << queue.front() << endl; // Output: 10

    cout << "Dequeued: " << queue.dequeue() << endl; // Output: 10
    cout << "Dequeued: " << queue.dequeue() << endl; // Output: 20

    cout << "Front of queue: " << queue.front() << endl; // Output: 30

    queue.dequeue(); // Removes 30
    queue.dequeue(); // Queue underflow

    return 0;
}
