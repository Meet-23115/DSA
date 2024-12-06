#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x) , next(nullptr) {} ;
};

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    for (int i = 0; i < 10; i++)
    {
        Node *node = new Node(i);
        if(head == nullptr){
            head = node;
            tail = node;
            tail -> next = head;
        }
        else{
            tail -> next = node;
            tail = node;
            tail ->next = head;
            
        }


    }
     // Traversing the circular linked list
    cout << "Circular Linked List: ";
    Node *current = head;
    if (current != nullptr)
    {
        do
        {
            cout << current->val << " ";
            current = current->next;
        } while (current != head);
    }
    cout << endl;

    // Deleting all nodes to free memory
    if (head != nullptr)
    {
        Node *current = head;
        do
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        } while (current != head);
    }
    return 0;
}