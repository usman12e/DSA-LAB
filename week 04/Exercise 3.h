#pragma once
#include <iostream>
using namespace std;

class Deque {
    int* arr, size, left, right;

public:
    Deque(int n) {
        size = n;
        arr = new int[size];
        left = right = -1;
    }

    ~Deque() {
        delete[] arr;
    }

    void insertLeft(int x) {
        if ((left == 0 && right == size - 1) || (left == right + 1)) {
            cout << "Overflow\n";
            return;
        }
        if (left == -1) {
            left = right = 0;
        }
        else if (left == 0) {
            left = size - 1;
        }
        else {
            left--;
        }
        arr[left] = x;
        cout << "Inserted " << x << " at left\n";
    }

    void insertRight(int x) {
        if ((left == 0 && right == size - 1) || (left == right + 1)) {
            cout << "Overflow\n";
            return;
        }
        if (right == -1) {
            left = right = 0;
        }
        else if (right == size - 1) {
            right = 0;
        }
        else {
            right++;
        }
        arr[right] = x;
        cout << "Inserted " << x << " at right\n";
    }

    void removeLeft() {
        if (left == -1) {
            cout << "Underflow\n";
            return;
        }
        cout << "Removed " << arr[left] << " from left\n";
        if (left == right) {
            left = right = -1;
        }
        else if (left == size - 1) {
            left = 0;
        }
        else {
            left++;
        }
    }

    void removeRight() {
        if (right == -1) {
            cout << "Underflow\n";
            return;
        }
        cout << "Removed " << arr[right] << " from right\n";
        if (left == right) {
            left = right = -1;
        }
        else if (right == 0) {
            right = size - 1;
        }
        else {
            right--;
        }
    }
};
