#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    void announce(){
        cout << "This is an object of class solution" << endl;
    }
    
};

int main(){

    Solution s;
    s.announce();
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    
    for(int i = 1; i <= 10; i++){
        ListNode* newNode = new ListNode(i);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;   
        }
    }

    ListNode* current = head;

    while(current != nullptr){
        cout << current->val << " ";
        current = current->next;
    }
    

    return 0;
}