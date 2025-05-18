#include<iostream>
using namespace std;

int main() {
    Deque<int> dq(5);
    dq.insertLeft(1);
    dq.insertRight(2);
    dq.insertLeft(3);
    dq.insertRight(4);
    dq.removeLeft();
    dq.removeRight();
    return 0;
}
