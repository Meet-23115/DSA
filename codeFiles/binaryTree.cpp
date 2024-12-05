#include <iostream>
using namespace std;

// Define a tree node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    // Helper for recursive insertion
    TreeNode* insert(TreeNode* node, int x) {
        if (node == nullptr) {
            return new TreeNode(x); // Create a new node if the current node is null
        }

        if (x < node->val) {
            node->left = insert(node->left, x); // Insert in the left subtree
        } else {
            node->right = insert(node->right, x); // Insert in the right subtree
        }

        return node;
    }

    // Helper for in-order traversal
    void inOrder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        inOrder(node->left);        // Visit left subtree
        cout << node->val << " ";  // Visit current node
        inOrder(node->right);      // Visit right subtree
    }

    // Helper for searching a value
    bool search(TreeNode* node, int x) {
        if (node == nullptr) {
            return false; // Value not found
        }

        if (node->val == x) {
            return true; // Value found
        }

        if (x < node->val) {
            return search(node->left, x); // Search in the left subtree
        } else {
            return search(node->right, x); // Search in the right subtree
        }
    }

    // Helper for deleting the tree
    void deleteTree(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        deleteTree(node->left);  // Delete left subtree
        deleteTree(node->right); // Delete right subtree
        delete node;             // Delete current node
    }

public:
    BinaryTree() : root(nullptr) {}

    // Public method to insert a value
    void insert(int x) {
        root = insert(root, x);
    }

    // Public method for in-order traversal
    void inOrderTraversal() {
        inOrder(root);
        cout << endl;
    }

    // Public method to search for a value
    bool search(int x) {
        return search(root, x);
    }

    // Destructor to free memory
    ~BinaryTree() {
        deleteTree(root);
    }
};

int main() {
    BinaryTree tree;

    // Insert values into the tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Display in-order traversal
    cout << "In-order traversal: ";
    tree.inOrderTraversal(); // Output: 20 30 40 50 60 70 80

    // Search for values
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl; // Output: Found
    cout << "Search 90: " << (tree.search(90) ? "Found" : "Not Found") << endl; // Output: Not Found

    return 0;
}
