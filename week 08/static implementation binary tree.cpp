#include <iostream>
#define SIZE 100
using namespace std;

class StaticBinaryTree {
private:
    int tree[SIZE];
    bool isPresent[SIZE];  // to track if a node exists at that position

public:
    StaticBinaryTree() {
        for (int i = 0; i < SIZE; i++) {
            isPresent[i] = false;
        }
    }

    void insert(int value, int index = 0) {
        if (index >= SIZE) {
            cout << "Tree overflow!" << endl;
            return;
        }
        if (!isPresent[index]) {
            tree[index] = value;
            isPresent[index] = true;
        }
        else {
            cout << "Node already exists at index " << index << endl;
        }
    }

    void insertLeft(int parentIndex, int value) {
        insert(value, 2 * parentIndex + 1);
    }

    void insertRight(int parentIndex, int value) {
        insert(value, 2 * parentIndex + 2);
    }

    void inorder(int index = 0) {
        if (index >= SIZE || !isPresent[index]) return;
        inorder(2 * index + 1);
        cout << tree[index] << " ";
        inorder(2 * index + 2);
    }
};

int main() {
    StaticBinaryTree bt;
    bt.insert(10); // root
    bt.insertLeft(0, 5);
    bt.insertRight(0, 15);
    bt.insertLeft(1, 2);
    bt.insertRight(1, 7);

    cout << "Inorder Traversal: ";
    bt.inorder();
    cout << endl;
    return 0;
}
