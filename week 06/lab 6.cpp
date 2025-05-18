#pragma once
#include <iostream>
#include <cstdlib> 
#include <conio.h>
using namespace std;

template<class ItemType>
class List
{
protected:
    struct node {
        ItemType info;
        struct node* next;
    };
    typedef struct node* NODEPTR;
    NODEPTR listptr;
public:
    List();
    ~List();
    bool emptyList();
    void insertafter(ItemType oldvalue, ItemType newvalue);
    void deleteItem(ItemType oldvalue);
    void push(ItemType newvalue);
    ItemType pop();
};

template<class ItemType>
List<ItemType>::List() {
    listptr = nullptr;
}

template<class ItemType>
List<ItemType>::~List()
{
    NODEPTR p, q;
    if (emptyList()) {
        return;
    }
    for (p = listptr; p != nullptr; p = q) {
        q = p->next;
        delete p;
    }
}

template <class ItemType>
void List<ItemType>::insertafter(ItemType oldvalue, ItemType newvalue)
{
    NODEPTR p, q;
    for (p = listptr; p != nullptr && p->info != oldvalue; p = p->next);

    if (p == nullptr) {
        cout << "ERROR: value sought is not in the list.";
        exit(1);
    }

    q = new node;
    q->info = newvalue;
    q->next = p->next;
    p->next = q;
}

template<class ItemType>
bool List<ItemType>::emptyList()
{
    return (listptr == nullptr);
}

template<class ItemType>
void List<ItemType>::push(ItemType newvalue)
{
    NODEPTR p = new node;
    p->info = newvalue;
    p->next = listptr;
    listptr = p;
    cout << newvalue << endl;
}

template<class ItemType>
void List<ItemType>::deleteItem(ItemType oldvalue)
{
    NODEPTR p, q;
    for (q = nullptr, p = listptr; p != nullptr && p->info != oldvalue; q = p, p = p->next);

    if (p == nullptr) {
        cout << "ERROR: value sought is not in the List.";
        exit(1);
    }

    if (q == nullptr) {
        listptr = p->next;
    }
    else {
        q->next = p->next;
    }
    delete p;
}

template<class ItemType>
ItemType List<ItemType>::pop()
{
    if (emptyList()) {
        cout << "ERROR: the List is empty.";
        exit(1);
    }

    NODEPTR p = listptr;
    ItemType x = p->info;
    listptr = p->next;
    delete p;

    return x;
}
//Exercise 6.3
#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

class LinkedStr {
private:
    Node* ptr;

public:
    LinkedStr();                // Constructor
    ~LinkedStr();               // Destructor
    void makeStr(int len);
    void displayStr();
    void removeFirst();
    void removeLast();
    void remove(int k);
};

// Constructor
LinkedStr::LinkedStr() {
    ptr = nullptr;
}

// Destructor
LinkedStr::~LinkedStr() {
    Node* temp;
    while (ptr != nullptr) {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
}

// Create a linked list with user input
void LinkedStr::makeStr(int len) {
    Node* temp, * tail = nullptr;
    for (int i = 0; i < len; i++) {
        temp = new Node;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> temp->info;
        temp->next = nullptr;
        if (ptr == nullptr) {
            ptr = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
}

// Display all elements
void LinkedStr::displayStr() {
    Node* temp = ptr;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Remove first node
void LinkedStr::removeFirst() {
    if (ptr == nullptr) return;
    Node* temp = ptr;
    ptr = ptr->next;
    delete temp;
}

// Remove last node
void LinkedStr::removeLast() {
    if (ptr == nullptr) return;

    if (ptr->next == nullptr) {
        delete ptr;
        ptr = nullptr;
        return;
    }

    Node* current = ptr;
    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}

// Remove node with value k
void LinkedStr::remove(int k) {
    if (ptr == nullptr) return;

    // If head needs to be deleted
    if (ptr->info == k) {
        Node* temp = ptr;
        ptr = ptr->next;
        delete temp;
        return;
    }

    Node* prev = ptr;
    Node* current = ptr->next;

    while (current != nullptr && current->info != k) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        prev->next = current->next;
        delete current;
    }
}
#include"list.cpp"

int main() {
    //Exercise 6.1
    List<int> l;
    l.push(87);
    cout << "Pushing values 88, 89, 91, 93 onto the list:\n";
    l.push(88);
    l.push(89);
    l.push(91);
    l.push(93);

    cout << "Inserting 90 after 20:\n";
    l.insertafter(89, 90);

    cout << "Deleting value 10:\n";
    l.deleteItem(91);

    cout << "Popping top value: " << l.pop() << endl;

    if (l.emptyList()) {
        cout << "List is now empty.\n";
    }
    else {
        cout << "List is not empty.\n";
    }
    //Exercise 6.2
    string input = "hello";
    List<char> charList;

    for (char c : input) {
        charList.push(c);
    }

    cout << "Reversed string: ";
    while (!charList.emptyList()) {
        cout << charList.pop();
    }
    cout << endl;
    //Exercise 6.3
    LinkedStr list;

    list.makeStr(5);  // Create a list of 5 elements
    list.displayStr();

    cout << "Removing first element...\n";
    list.removeFirst();
    list.displayStr();

    cout << "Removing last element...\n";
    list.removeLast();
    list.displayStr();

    int k;
    cout << "Enter value to remove: ";
    cin >> k;
    list.remove(k);
    list.displayStr();

    return 0;

    getch();
    return 0;
}