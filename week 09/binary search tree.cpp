#include <iostream>
using namespace std;

template <typename T>
class BSTNode {
public:
    T data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(const T& val) : data(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
private:
    BSTNode<T>* root;

    // Recursive insert
    BSTNode < T* insert(BSTNode<T>* node, const T& val) {
        if (!node) return new BSTNode<T>(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);
        return node;
    }

    // Inorder traversal storing values in array
    void inorder(BSTNode<T>* node, T* arr, int& index) const {
        if (!node) return;
        inorder(node->left, arr, index);
        arr[index++] = node->data;
        inorder(node->right, arr, index);
    }

    void clear(BSTNode<T>* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}
    ~BST() { clear(root); }

    void insert(const T& val) {
        root = insert(root, val);
    }

    void getSortedElements(T* arr, int& index) const {
        index = 0;
        inorder(root, arr, index);
    }
};
int main() {
    const int SIZE = 5;
    string names[SIZE] = { "Zara", "Ali", "David", "Eve", "Bob" };
    string sortedNames[SIZE];

    BST<string> bst;
    for (int i = 0; i < SIZE; ++i)
        bst.insert(names[i]);

    int sortedIndex = 0;
    bst.getSortedElements(sortedNames, sortedIndex);

    cout << "Sorted Names:" << endl;
    for (int i = 0; i < SIZE; ++i)
        cout << sortedNames[i] << endl;

    return 0;
}
