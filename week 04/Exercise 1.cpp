#include<iostream>
#include"Example and Exercise 1.h"
using namespace std;
int main() {
    Queue q1;
    int x;

    for (int i = 0; i < 10; i++) {
        q1.Insert(i);
    }

    for (int i = 0; i < 10; i++) {
        q1.Remove(x);
        cout << x << endl;
    }

    return 0;
}