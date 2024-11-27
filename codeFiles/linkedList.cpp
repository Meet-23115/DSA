#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head; // Points to the first node of the list

public:
    LinkedList() : head(nullptr) {}

    // Add a node to the end of the list
    void append(int x) {
        ListNode* newNode = new ListNode(x);
        if (head == nullptr) { // If the list is empty
            head = newNode;
        } else {
            ListNode* temp = head;
            while (temp->next != nullptr) { // Traverse to the end
                temp = temp->next;
            }
            temp->next = newNode; // Link the new node
        }
    }

    // Add a node to the beginning of the list
    void prepend(int x) {
        ListNode* newNode = new ListNode(x);
        newNode->next = head; // Link the new node to the current head
        head = newNode;       // Update the head pointer
    }

    // Remove a node with a specific value
    void remove(int x) {
        if (head == nullptr) {
            cout << "List is empty. Nothing to remove." << endl;
            return;
        }

        if (head->val == x) { // If the head contains the value
            ListNode* temp = head;
            head = head->next; // Update head to the next node
            delete temp;
            return;
        }

        ListNode* current = head;
        while (current->next != nullptr && current->next->val != x) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << "Value " << x << " not found in the list." << endl;
        } else {
            ListNode* temp = current->next;
            current->next = current->next->next; // Bypass the node to remove
            delete temp;
        }
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Destructor: Clean up memory
    ~LinkedList() {
        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    // Test operations
    list.append(10);
    list.append(20);
    list.append(30);

    cout << "After appending 10, 20, 30: ";
    list.display();

    list.prepend(5);
    cout << "After prepending 5: ";
    list.display();

    list.remove(20);
    cout << "After removing 20: ";
    list.display();

    list.remove(50); // Attempt to remove a non-existent value
    cout << "After attempting to remove 50: ";
    list.display();

    return 0;
}
