
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
    node *head = nullptr; 
    node *tail = nullptr; 

    
    for (int i = 0; i < 10; i++)
    {
        node *n = new node(i);
        if (head == nullptr)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
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
