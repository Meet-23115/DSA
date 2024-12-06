
#include <iostream>
using namespace std;

// Definition of the node structure
struct node
{
    int val;
    node *next;
    node(int value) : val(value), next(nullptr) {}
};

int main()
{
    node *head = nullptr; // Initialize head to nullptr
    node *tail = nullptr; // Initialize tail to nullptr

    // Create linked list
    for (int i = 0; i < 10; i++)
    {
        node *n = new node(i); // Dynamically allocate a new node
        if (head == nullptr)
        {
            head = n; // If the list is empty, set head to the new node
            tail = n; // Tail is also the new node
        }
        else
        {
            tail->next = n;    // Link the current tail to the new node
            tail = tail->next; // Move the tail pointer to the new node
        }
    }

    // Print the linked list
    node *current = head; // Start from the head
    while (current != nullptr)
    {
        cout << current->val << endl;
        current = current->next; // Move to the next node
    }

    // Free allocated memory
    current = head; // Start from the head again
    while (current != nullptr)
    {
        node *temp = current;
        current = current->next; // Move to the next node
        delete temp;             // Delete the current node
    }

    return 0;
}
