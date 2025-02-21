#pragma once
#define Max_Items 100
typedef int ItemType;

#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    char items[Max_Items];

public:
    Stack();
    ~Stack();
    bool isEmpty() const;
    bool isFull() const;
    void push(char newitem);
    void pop(char& item);
    int  peek() const;
    void reverse(string input);

};