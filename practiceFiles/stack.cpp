#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

class Stack
{
private:
    Node *topNode;

public:
    Stack() : topNode(nullptr) {};

    void push(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
    }
    int pop()
    {
        if (isEmpty())
        {
            throw runtime_error("Stack is empty");
        }
        else
        {
            int val = topNode->val;
            Node *temp = topNode;
            topNode = topNode->next;
            delete temp;
            return val;
        }
    }
    int top()
    {
        if (isEmpty())
        {
            throw runtime_error("Stack is empty");
        }
        else
        {
            return topNode->val;
        }
    }

    bool isEmpty()
    {
        return topNode == nullptr;
    }
    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

int main()
{
    try
    {
        Stack stack;
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);
        cout << "Top element is " << stack.top() << endl;
        stack.pop();
        cout << "Top element is " << stack.top() << endl;
        stack.pop();
        cout << "Top element is " << stack.top() << endl;
        stack.pop();
        cout << "Top element is " << stack.top() << endl;
        stack.pop();
        cout << "Top element is " << stack.top() << endl;
        stack.pop();
        stack.pop();
    }
    catch (const exception& e)
    {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}