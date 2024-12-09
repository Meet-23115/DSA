#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

int main()
{
    Node *root = nullptr;
    for (int i = 0; i < 10; i++)
    {
        Node *node = new Node(i);
        if (root == nullptr)
        {
            root = node;
        }
    }
    return 0;
}