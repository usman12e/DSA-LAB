#include <iostream>
using namespace std;

class Node {
public:
    int digit;
    Node* prev;
    Node* next;
    Node(int d) : digit(d), prev(nullptr), next(nullptr) {}
};

class LongInt {
private:
    Node* head;
    Node* tail;

public:
    LongInt() : head(nullptr), tail(nullptr) {}

    void insertFront(int d) {
        Node* newNode = new Node(d);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->digit;
            temp = temp->next;
        }
        cout << endl;
    }

    static LongInt add(LongInt num1, LongInt num2) {
        LongInt result;
        Node* t1 = num1.tail;
        Node* t2 = num2.tail;
        int carry = 0;

        while (t1 || t2 || carry) {
            int sum = carry;
            if (t1) { sum += t1->digit; t1 = t1->prev; }
            if (t2) { sum += t2->digit; t2 = t2->prev; }
            result.insertFront(sum % 10);
            carry = sum / 10;
        }
        return result;
    }
};

int main() {
    LongInt num1, num2;
    string str1 = "987654321";
    string str2 = "123456789";

    for (char ch : str1) num1.insertFront(ch - '0');
    for (char ch : str2) num2.insertFront(ch - '0');

    cout << "Number 1: "; num1.display();
    cout << "Number 2: "; num2.display();

    LongInt sum = LongInt::add(num1, num2);
    cout << "Sum: "; sum.display();

    return 0;
}
