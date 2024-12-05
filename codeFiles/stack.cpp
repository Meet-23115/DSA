#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Stack {
private:
    ListNode* topNode; // Pointer to the top of the stack

public:
    Stack() : topNode(nullptr) {}

    // Push operation: Add an element to the top of the stack
    void push(int x) {
        ListNode* newNode = new ListNode(x);
        newNode->next = topNode;
        topNode = newNode;
    }

    // Pop operation: Remove and return the top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return -1; // Return -1 to indicate an error
        }
        int value = topNode->val;
        ListNode* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return value;
    }

    // Peek/Top operation: Return the top element without removing it
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element." << endl;
            return -1; // Return -1 to indicate an error
        }
        return topNode->val;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Destructor: Clean up dynamically allocated memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;

    // Test operations
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top of stack: " << stack.top() << endl; // Output: 30

    cout << "Popped: " << stack.pop() << endl; // Output: 30
    cout << "Popped: " << stack.pop() << endl; // Output: 20

    cout << "Top of stack: " << stack.top() << endl; // Output: 10

    stack.pop(); // Removes 10
    stack.pop(); // Stack underflow

    return 0;
}
