#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(const T& val) {
        data = val;
        left = right = nullptr;
    }
};

template <typename T>
class BinaryTree {
private:
    Node<T>* root;

    // Helper functions
    void inorder(Node<T>* node) const {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node<T>* node) const {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node<T>* node) const {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    Node<T>* getRoot() const {
        return root;
    }

    void insertRoot(const T& val) {
        if (!root)
            root = new Node<T>(val);
        else
            cout << "Root already exists!" << endl;
    }

    void insertLeft(Node<T>* parent, const T& val) {
        if (!parent->left)
            parent->left = new Node<T>(val);
        else
            cout << "Left child already exists!" << endl;
    }

    void insertRight(Node<T>* parent, const T& val) {
        if (!parent->right)
            parent->right = new Node<T>(val);
        else
            cout << "Right child already exists!" << endl;
    }

    // Public traversal methods
    void inorderTraversal() const {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    void preorderTraversal() const {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }

    void postorderTraversal() const {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }
};
