#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    Node* getRoot() {
        return root;
    }

    void insertRoot(int val) {
        if (!root)
            root = new Node(val);
        else
            cout << "Root already exists!" << endl;
    }

    void insertLeft(Node* parent, int val) {
        if (!parent->left)
            parent->left = new Node(val);
        else
            cout << "Left child already exists!" << endl;
    }

    void insertRight(Node* parent, int val) {
        if (!parent->right)
            parent->right = new Node(val);
        else
            cout << "Right child already exists!" << endl;
    }

    void inorderTraversal() {
        inorder(root);
    }
};

int main() {
    BinaryTree bt;
    bt.insertRoot(10);
    Node* root = bt.getRoot();
    bt.insertLeft(root, 5);
    bt.insertRight(root, 15);
    bt.insertLeft(root->left, 2);
    bt.insertRight(root->left, 7);

    cout << "Inorder Traversal: ";
    bt.inorderTraversal();
    cout << endl;
    return 0;
}
