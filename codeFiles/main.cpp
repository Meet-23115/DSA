#include <iostream>
using namespace std;

struct MeetCode {
    int val;
    MeetCode* value;
    MeetCode(int x) : val(x), value(nullptr) {}
};

class Meet {
private:
    MeetCode* meet; // Class member pointer
public:
    Meet() : meet(nullptr) {} // Initialize `meet` to nullptr in the constructor

    void call(int a) {
        meet = new MeetCode(a); // Assign to the member variable
    }

    void display() {
        if (meet) { // Check if `meet` is initialized
            cout << meet->val << endl;
        } else {
            cout << "MeetCode object is not initialized!" << endl;
        }
    }

    ~Meet() {
        delete meet; // Free memory allocated for `meet` to prevent leaks
    }
};

int main() {
    Meet m;
    
    m.call(21);   // Initialize with a value
    m.display();  // Display the value
    return 0;
}
