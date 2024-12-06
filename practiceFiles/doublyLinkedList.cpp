#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *prev;
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    for (int i = 0; i < 10; ++i)
    {
        Node *node = new Node(i);
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = tail->next;
        }
    }

    Node *current = tail;
    for (int i = 0; i < 10; i++)
    {
        cout << current->val << " ";
        current = current->prev;
    }

    current = head;
    while(current != nullptr){
        Node *temp = current;
        current = current -> next;
        delete temp;
    }
    return 0;
}