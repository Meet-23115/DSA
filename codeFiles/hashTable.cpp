#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class HashTable {
private:
    vector<list<pair<string, int>>> table; // Vector of lists for chaining
    int size;

    int hashFunction(const string& key) {
        // Compute a simple hash value using the sum of ASCII values
        int hash = 0;
        for (char ch : key) {
            hash += ch;
        }
        return hash % size;
    }

public:
    HashTable(int size) : size(size) {
        table.resize(size); // Initialize the table with empty lists
    }

    void insert(const string& key, int value) {
        int index = hashFunction(key);
        // Check if the key already exists, and update if it does
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        // If key doesn't exist, add it to the list
        table[index].emplace_back(key, value);
    }

    int search(const string& key) {
        int index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return -1; // Key not found
    }

    bool remove(const string& key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it); // Remove the key-value pair
                return true;
            }
        }
        return false; // Key not found
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Bucket " << i << ": ";
            for (const auto& pair : table[i]) {
                cout << "(" << pair.first << ", " << pair.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(10); // Create a hash table with 10 buckets

    ht.insert("apple", 100);
    ht.insert("banana", 200);
    ht.insert("cherry", 300);
    ht.insert("apple", 400); // Update value for 'apple'

    cout << "Search 'apple': " << ht.search("apple") << endl; // Output: 400
    cout << "Search 'banana': " << ht.search("banana") << endl; // Output: 200

    ht.remove("banana"); // Remove 'banana'
    cout << "Search 'banana': " << ht.search("banana") << endl; // Output: -1 (not found)

    cout << "Hash Table contents:" << endl;
    ht.display();

    return 0;
}
