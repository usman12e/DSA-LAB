#pragma once
#include <iostream>
using namespace std;

#define maxQue 100
typedef int ItemType;

class Queue {
private:
    ItemType items[maxQue];
    int front, rear, count;

public:
    Queue();
    int IsEmpty();
    int IsFull();
    void Insert(ItemType newItem);
    void Remove(ItemType& item);
};

Queue::Queue() {
    count = 0;
    front = 0;
    rear = 0;
}

int Queue::IsEmpty() {
    return (count == 0);
}

int Queue::IsFull() {
    return (count == maxQue);
}

void Queue::Insert(ItemType newItem) {
    if (IsFull())
        cout << "Over Flow" << endl;
    else {
        items[rear] = newItem;
        rear = (rear + 1) % maxQue;
        count++;
    }
}

void Queue::Remove(ItemType& item) {
    if (IsEmpty())
        cout << "Under Flow" << endl;
    else {
        item = items[front];
        front = (front + 1) % maxQue;
        count--;
    }
}

