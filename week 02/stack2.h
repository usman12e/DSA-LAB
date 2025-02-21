#include<stdlib.h>
#include<iostream>
#include"stack.h"
//TASK NO 1 QN 01
// ---------------
//Stack::Stack() {
//	top = -1;
//}
//int Stack::IsEmpty() const {
//	return (top == -1);
//}
//int Stack::IsFull() const {
//	return(top == Max_Items - 1);
//}
//void Stack::push(ItemType newItem) {
//	if (IsFull()) {
//		cout << "Stack Overflow" << endl;
//		exit(1);
//	}
//	top++;
//	items[top] = newItem;
//}
//void Stack::pop(ItemType& item) {
//	if (IsFull()) {
//		cout << "Stack Underflow" << endl;
//		exit(1);
//	}
//	item = items[top];
//	top--;
//}
//void Stack::peek(ItemType& peitem) {
//	if (IsFull()) {
//		cout << "Stack Underflow" << endl;
//		exit(1);
//	}
//TASK no 2 QN 01
//------------------
#include "stack.h"
#include<string>

#include <stdlib.h>

Stack::Stack() {
    top = -1;
}

Stack::~Stack() {

}

bool Stack::isEmpty() const {
    return (top == -1);
}

bool Stack::isFull() const {
    return (top == Max_Items - 1);
}

void Stack::push(char newitem) {
    if (isFull()) {
        cout << "Stack overflow" << endl;
        exit(1);
    }
    top++;
    items[top] = newitem;
}

void Stack::pop(char& item) {
    if (isEmpty()) {
        cout << "Stack underflow" << endl;
        exit(1);
    }
    item = items[top];
    top--;
}

int Stack::peek() const {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        exit(1);
    }
    return items[top];
}
void Stack::reverse(string input) {
    char c;
    string reversed = "";


    for (char c : input) {
        push(c);
    }
    while (!isEmpty())
    {
        pop(c);

        reversed =reversed+c;

    }
    cout << reversed;
}

